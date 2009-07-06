/**
 * Copyright (C) 2007-2009 Felipe Contreras
 * Copyright (C) 1998-2006 Pidgin (see pidgin-copyright)
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include "slpmsg.h"
#include "pn_peer_link.h"

#include "pn_peer_call.h"
#include "session.h"

#include "cmd/msg_private.h"

#include <glib/gstdio.h>
#include <string.h>

/* libpurple stuff. */
#include "fix_purple.h"

MsnSlpMessage *
msn_slpmsg_new(PnPeerLink *link)
{
    MsnSlpMessage *slpmsg;

    slpmsg = g_new0(MsnSlpMessage, 1);

#ifdef PECAN_DEBUG_SLPMSG
    pn_info("slpmsg new (%p)\n", slpmsg);
#endif

    slpmsg->link = link;

    link->slp_msgs = g_list_append(link->slp_msgs, slpmsg);

    return slpmsg;
}

void
msn_slpmsg_destroy(MsnSlpMessage *slpmsg)
{
    PnPeerLink *link;
    GList *cur;

    if (!slpmsg)
	    return;

#ifdef PECAN_DEBUG_SLPMSG
    pn_info("slpmsg destroy (%p)\n", slpmsg);
#endif

    link = slpmsg->link;

    if (slpmsg->fp)
        fclose(slpmsg->fp);

    g_free(slpmsg->buffer);

    for (cur = slpmsg->msgs; cur; cur = cur->next) {
        /* Something is pointing to this slpmsg, so we should remove that
         * pointer to prevent a crash. */
        /* Ex: a user goes offline and after that we receive an ACK */

        MsnMessage *msg = cur->data;

#ifdef PECAN_DEBUG_SLPMSG
        pn_info("Unlink slpmsg callbacks.\n");
#endif

        msg->ack_cb = NULL;
        msg->nak_cb = NULL;
        msg->ack_data = NULL;
    }

    link->slp_msgs = g_list_remove(link->slp_msgs, slpmsg);

    g_free(slpmsg);
}

void
msn_slpmsg_set_body(MsnSlpMessage *slpmsg,
                    gconstpointer *body,
                    guint64 size)
{
    if (body)
        slpmsg->buffer = g_memdup(body, size);
    else
        slpmsg->buffer = g_malloc0(size);

    slpmsg->size = size;
}

void
msn_slpmsg_set_image(MsnSlpMessage *slpmsg,
                     PnBuffer *image)
{
    slpmsg->size = image->len;
    slpmsg->buffer = g_memdup(image->data, slpmsg->size);
}

void
msn_slpmsg_open_file(MsnSlpMessage *slpmsg,
                     const char *file_name)
{
    struct stat st;

    slpmsg->fp = g_fopen(file_name, "rb");

    if (g_stat(file_name, &st) == 0)
        slpmsg->size = st.st_size;
}

#ifdef PECAN_DEBUG_SLP
void
msn_slpmsg_show(MsnMessage *msg)
{
    const char *info;
    gboolean text;

    text = FALSE;

    switch (msg->msnslp_header.flags) {
        case 0x0:
            info = "SLP CONTROL";
            text = TRUE;
            break;
        case 0x2:
            info = "SLP ACK"; break;
        case 0x20:
        case 0x1000030:
            info = "SLP DATA"; break;
        case 0x100:
            info = "SLP DC"; break;
        default:
            info = "SLP UNKNOWN"; break;
    }

    msn_message_show_readable(msg, info, text);
}
#endif

MsnSlpMessage *
msn_slpmsg_sip_new(PnPeerCall *call,
                   int cseq,
                   const char *header,
                   const char *branch,
                   const char *content_type,
                   const char *content)
{
    PnPeerLink *link;
    MsnSlpMessage *slpmsg;
    gchar *body;
    gsize body_len;
    gsize content_len;

    link = call->link;

    /* Let's remember that "content" should end with a 0x00 */

    content_len = content ? strlen(content) + 1 : 0;

    body = g_strdup_printf("%s\r\n"
                           "To: <msnmsgr:%s>\r\n"
                           "From: <msnmsgr:%s>\r\n"
                           "Via: MSNSLP/1.0/TLP ;branch={%s}\r\n"
                           "CSeq: %d\r\n"
                           "Call-ID: {%s}\r\n"
                           "Max-Forwards: 0\r\n"
                           "Content-Type: %s\r\n"
                           "Content-Length: %" G_GSIZE_FORMAT "\r\n"
                           "\r\n",
                           header,
                           link->remote_user,
                           link->local_user,
                           branch,
                           cseq,
                           call->id,
                           content_type,
                           content_len);

    body_len = strlen(body);

    if (content_len > 0) {
        body_len += content_len;
        body = g_realloc(body, body_len);
        g_strlcat(body, content, body_len);
    }

    slpmsg = msn_slpmsg_new(link);
    msn_slpmsg_set_body(slpmsg, (gpointer) body, body_len);

    slpmsg->sip = TRUE;
    slpmsg->call = call;

    g_free(body);

    return slpmsg;
}

/*
 * Copyright (C) 2006-2008 Felipe Contreras.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MSN_CONN_PRIVATE_H
#define MSN_CONN_PRIVATE_H

#include <glib-object.h>

#include "conn.h"

typedef struct ConnObjectClass ConnObjectClass;

#define CONN_OBJECT_ERROR conn_object_error_quark ()

/* Forward declarations */

struct _PurpleProxyConnectData;
struct MsnSesion;

GQuark conn_object_error_quark (void);

struct ConnObject
{
    GObject parent;
    gboolean dispose_has_run;

    GError *error; /**< The current IO error .*/
    guint read_watch; /** < The source id of the read watch. */

    ConnObjectType type;

    gchar *name;

    gpointer data; /**< Client data. */
    gpointer foo_data;
    ConnObject *prev;
    ConnObject *next;

    GIOChannel *channel; /**< The current IO channel .*/

    gchar *hostname;
    guint port;

    struct _PurpleProxyConnectData *connect_data;
    struct MsnSession *session;
    gulong open_sig_handler;
    gulong close_sig_handler;
    gulong error_sig_handler;
};

struct ConnObjectClass
{
    GObjectClass parent_class;

    guint open_sig;
    guint close_sig;

    GIOStatus (*read) (ConnObject *conn, gchar *buf, gsize count, gsize *bytes_read, GError **error);
    GIOStatus (*write) (ConnObject *conn, const gchar *buf, gsize count, gsize *bytes_written, GError **error);
    void (*error) (ConnObject *conn);
    void (*connect) (ConnObject *conn, const gchar *hostname, gint port);
    void (*close) (ConnObject *conn);
    void (*parse) (ConnObject *conn, gchar *buf, gsize bytes_read);

};

#define CONN_OBJECT_TYPE (conn_object_get_type ())
#define CONN_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONN_OBJECT_TYPE, ConnObject))
#define CONN_OBJECT_CLASS(c) (G_TYPE_CHECK_CLASS_CAST ((c), CONN_OBJECT_TYPE, ConnObjectClass))
#define CONN_IS_OBJECT(obj) (G_TYPE_CHECK_TYPE ((obj), CONN_OBJECT_TYPE))
#define CONN_IS_OBJECT_CLASS(c) (G_TYPE_CHECK_CLASS_TYPE ((c), CONN_OBJECT_TYPE))
#define CONN_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CONN_OBJECT_TYPE, ConnObjectClass))

GType conn_object_get_type ();

#endif /* MSN_CONN_PRIVATE_H */
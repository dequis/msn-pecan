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

#ifndef PECAN_STATUS_H
#define PECAN_STATUS_H

#include <glib.h>

/**
 * Status types.
 */
typedef enum
{
    PECAN_STATUS_OFFLINE,
    PECAN_STATUS_ONLINE,
    PECAN_STATUS_BUSY,
    PECAN_STATUS_IDLE,
    PECAN_STATUS_BRB,
    PECAN_STATUS_AWAY,
    PECAN_STATUS_PHONE,
    PECAN_STATUS_LUNCH,
    PECAN_STATUS_HIDDEN,
    PECAN_STATUS_WRONG,
} PecanStatus;

struct MsnSession;

/**
 * Updates the status of the user.
 *
 * @param session The MSN session.
 */
void pecan_update_status (struct MsnSession *session);

/**
 * Updates the personal message of the user.
 *
 * @param session The MSN session.
 */
void pecan_update_personal_message (struct MsnSession *session);

gboolean pecan_timeout_tune_status (gpointer data);

#endif /* PECAN_STATUS_H */

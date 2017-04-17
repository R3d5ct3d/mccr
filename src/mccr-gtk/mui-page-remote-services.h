/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * mccr-gtk - GTK+ tool to manage MagTek Credit Card Readers
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301 USA.
 *
 * Copyright (C) 2017 Zodiac Inflight Innovations
 * Copyright (C) 2017 Aleksander Morgado <aleksander@aleksander.es>
 */

#ifndef MUI_PAGE_REMOTE_SERVICES_H
#define MUI_PAGE_REMOTE_SERVICES_H

#include <gtk/gtk.h>

#include "mui-page.h"

G_BEGIN_DECLS

#define MUI_TYPE_PAGE_REMOTE_SERVICES         (mui_page_remote_services_get_type ())
#define MUI_PAGE_REMOTE_SERVICES(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), MUI_TYPE_PAGE_REMOTE_SERVICES, MuiPageRemoteServices))
#define MUI_PAGE_REMOTE_SERVICES_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST ((k), MUI_TYPE_PAGE_REMOTE_SERVICES, MuiPageRemoteServicesClass))
#define MUI_IS_PAGE_REMOTE_SERVICES(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), MUI_TYPE_PAGE_REMOTE_SERVICES))
#define MUI_IS_PAGE_REMOTE_SERVICES_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), MUI_TYPE_PAGE_REMOTE_SERVICES))
#define MUI_PAGE_REMOTE_SERVICES_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), MUI_TYPE_PAGE_REMOTE_SERVICES, MuiPageRemoteServicesClass))

typedef struct _MuiPageRemoteServices        MuiPageRemoteServices;
typedef struct _MuiPageRemoteServicesClass   MuiPageRemoteServicesClass;
typedef struct _MuiPageRemoteServicesPrivate MuiPageRemoteServicesPrivate;

struct _MuiPageRemoteServices {
    MuiPage                       parent_instance;
    MuiPageRemoteServicesPrivate *priv;
};

struct _MuiPageRemoteServicesClass {
    MuiPageClass parent_class;

    /* signals */
    void (* operation_started)  (MuiPageRemoteServices *self);
    void (* operation_finished) (MuiPageRemoteServices *self);
};

GType mui_page_remote_services_get_type (void) G_GNUC_CONST;

GtkWidget *mui_page_remote_services_new                   (void);
gboolean   mui_page_remote_services_get_operation_ongoing (MuiPageRemoteServices *self);

G_END_DECLS

#endif /* MUI_PAGE_REMOTE_SERVICES_H */

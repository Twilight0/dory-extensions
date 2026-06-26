/*
 * Copyright (C) 2011 Red Hat, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301 USA.
 *
 * The DoryPreview project hereby grant permission for non-gpl compatible GStreamer
 * plugins to be used and distributed together with GStreamer and DoryPreview. This
 * permission is above and beyond the permissions granted by the GPL license
 * DoryPreview is covered by.
 *
 * Authors: Cosimo Cecchi <cosimoc@redhat.com>
 *
 */

#ifndef __DORY_PREVIEW_UTILS_H__
#define __DORY_PREVIEW_UTILS_H__

#include <clutter/clutter.h>
#include <xreader-document.h>
#include <gdk/gdk.h>

G_BEGIN_DECLS

ClutterActor * dory_preview_create_rounded_background (void);
GdkWindow *    dory_preview_create_foreign_window (guint xid);
gchar **       dory_preview_query_supported_document_types (void);

G_END_DECLS

#endif /* __DORY_PREVIEW_UTILS_H__ */

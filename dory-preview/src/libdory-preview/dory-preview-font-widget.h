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

#ifndef __DORY_PREVIEW_FONT_WIDGET_H__
#define __DORY_PREVIEW_FONT_WIDGET_H__

#include <glib-object.h>
#include <gtk/gtk.h>
#include <cairo/cairo-ft.h>

G_BEGIN_DECLS

#define DORY_PREVIEW_TYPE_FONT_WIDGET            (dory_preview_font_widget_get_type ())
#define DORY_PREVIEW_FONT_WIDGET(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), DORY_PREVIEW_TYPE_FONT_WIDGET, DoryPreviewFontWidget))
#define DORY_PREVIEW_IS_FONT_WIDGET(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DORY_PREVIEW_TYPE_FONT_WIDGET))
#define DORY_PREVIEW_FONT_WIDGET_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  DORY_PREVIEW_TYPE_FONT_WIDGET, DoryPreviewFontWidgetClass))
#define DORY_PREVIEW_IS_FONT_WIDGET_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  DORY_PREVIEW_TYPE_FONT_WIDGET))
#define DORY_PREVIEW_FONT_WIDGET_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  DORY_PREVIEW_TYPE_FONT_WIDGET, DoryPreviewFontWidgetClass))

typedef struct _DoryPreviewFontWidget          DoryPreviewFontWidget;
typedef struct _DoryPreviewFontWidgetPrivate   DoryPreviewFontWidgetPrivate;
typedef struct _DoryPreviewFontWidgetClass     DoryPreviewFontWidgetClass;

struct _DoryPreviewFontWidget
{
  GtkDrawingArea parent_instance;

  DoryPreviewFontWidgetPrivate *priv;
};

struct _DoryPreviewFontWidgetClass
{
  GtkDrawingAreaClass parent_class;
};

GType    dory_preview_font_widget_get_type     (void) G_GNUC_CONST;

DoryPreviewFontWidget *dory_preview_font_widget_new (const gchar *uri);

FT_Face dory_preview_font_widget_get_ft_face (DoryPreviewFontWidget *self);

const gchar *dory_preview_font_widget_get_uri (DoryPreviewFontWidget *self);

G_END_DECLS

#endif /* __DORY_PREVIEW_FONT_WIDGET_H__ */

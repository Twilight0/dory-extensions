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

#ifndef __DORY_PREVIEW_PDF_LOADER_H__
#define __DORY_PREVIEW_PDF_LOADER_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define DORY_PREVIEW_TYPE_PDF_LOADER            (dory_preview_pdf_loader_get_type ())
#define DORY_PREVIEW_PDF_LOADER(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), DORY_PREVIEW_TYPE_PDF_LOADER, DoryPreviewPdfLoader))
#define DORY_PREVIEW_IS_PDF_LOADER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DORY_PREVIEW_TYPE_PDF_LOADER))
#define DORY_PREVIEW_PDF_LOADER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  DORY_PREVIEW_TYPE_PDF_LOADER, DoryPreviewPdfLoaderClass))
#define DORY_PREVIEW_IS_PDF_LOADER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  DORY_PREVIEW_TYPE_PDF_LOADER))
#define DORY_PREVIEW_PDF_LOADER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  DORY_PREVIEW_TYPE_PDF_LOADER, DoryPreviewPdfLoaderClass))

typedef struct _DoryPreviewPdfLoader          DoryPreviewPdfLoader;
typedef struct _DoryPreviewPdfLoaderPrivate   DoryPreviewPdfLoaderPrivate;
typedef struct _DoryPreviewPdfLoaderClass     DoryPreviewPdfLoaderClass;

struct _DoryPreviewPdfLoader
{
  GObject parent_instance;

  DoryPreviewPdfLoaderPrivate *priv;
};

struct _DoryPreviewPdfLoaderClass
{
  GObjectClass parent_class;
};

GType    dory_preview_pdf_loader_get_type     (void) G_GNUC_CONST;

DoryPreviewPdfLoader *dory_preview_pdf_loader_new (const gchar *uri);
void dory_preview_pdf_loader_cleanup_document (DoryPreviewPdfLoader *self);
void dory_preview_pdf_loader_get_max_page_size (DoryPreviewPdfLoader *self,
                                         gdouble *width,
                                         gdouble *height);


G_END_DECLS

#endif /* __DORY_PREVIEW_PDF_LOADER_H__ */

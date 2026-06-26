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

#ifndef __DORY_PREVIEW_COVER_ART_H__
#define __DORY_PREVIEW_COVER_ART_H__

#include <glib-object.h>
#include <gst/tag/tag.h>

G_BEGIN_DECLS

#define DORY_PREVIEW_TYPE_COVER_ART_FETCHER            (dory_preview_cover_art_fetcher_get_type ())
#define DORY_PREVIEW_COVER_ART_FETCHER(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), DORY_PREVIEW_TYPE_COVER_ART_FETCHER, DoryPreviewCoverArtFetcher))
#define DORY_PREVIEW_IS_COVER_ART_FETCHER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DORY_PREVIEW_TYPE_COVER_ART_FETCHER))
#define DORY_PREVIEW_COVER_ART_FETCHER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  DORY_PREVIEW_TYPE_COVER_ART_FETCHER, DoryPreviewCoverArtFetcherClass))
#define DORY_PREVIEW_IS_COVER_ART_FETCHER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  DORY_PREVIEW_TYPE_COVER_ART_FETCHER))
#define DORY_PREVIEW_COVER_ART_FETCHER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  DORY_PREVIEW_TYPE_COVER_ART_FETCHER, DoryPreviewCoverArtFetcherClass))

typedef struct _DoryPreviewCoverArtFetcher          DoryPreviewCoverArtFetcher;
typedef struct _DoryPreviewCoverArtFetcherPrivate   DoryPreviewCoverArtFetcherPrivate;
typedef struct _DoryPreviewCoverArtFetcherClass     DoryPreviewCoverArtFetcherClass;

struct _DoryPreviewCoverArtFetcher
{
  GObject parent_instance;

  DoryPreviewCoverArtFetcherPrivate *priv;
};

struct _DoryPreviewCoverArtFetcherClass
{
  GObjectClass parent_class;
};

GType    dory_preview_cover_art_fetcher_get_type     (void) G_GNUC_CONST;
DoryPreviewCoverArtFetcher* dory_preview_cover_art_fetcher_new (GstTagList *taglist);

G_END_DECLS

#endif /* __DORY_PREVIEW_COVER_ART_H__ */

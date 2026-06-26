/*
 * Copyright (C) 2011 Lucas Rocha <lucasr@gnome.org>
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
 * Authors: Lucas Rocha <lucasr@gnome.org>
 *
 */

#ifndef __DORY_PREVIEW_SOUND_PLAYER_H__
#define __DORY_PREVIEW_SOUND_PLAYER_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define DORY_PREVIEW_TYPE_SOUND_PLAYER            (dory_preview_sound_player_get_type ())
#define DORY_PREVIEW_SOUND_PLAYER(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), DORY_PREVIEW_TYPE_SOUND_PLAYER, DoryPreviewSoundPlayer))
#define DORY_PREVIEW_IS_SOUND_PLAYER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), DORY_PREVIEW_TYPE_SOUND_PLAYER))
#define DORY_PREVIEW_SOUND_PLAYER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  DORY_PREVIEW_TYPE_SOUND_PLAYER, DoryPreviewSoundPlayerClass))
#define DORY_PREVIEW_IS_SOUND_PLAYER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  DORY_PREVIEW_TYPE_SOUND_PLAYER))
#define DORY_PREVIEW_SOUND_PLAYER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  DORY_PREVIEW_TYPE_SOUND_PLAYER, DoryPreviewSoundPlayerClass))

typedef struct _DoryPreviewSoundPlayer          DoryPreviewSoundPlayer;
typedef struct _DoryPreviewSoundPlayerPrivate   DoryPreviewSoundPlayerPrivate;
typedef struct _DoryPreviewSoundPlayerClass     DoryPreviewSoundPlayerClass;

typedef enum
{
  DORY_PREVIEW_SOUND_PLAYER_STATE_UNKNOWN = 0,
  DORY_PREVIEW_SOUND_PLAYER_STATE_IDLE    = 1,
  DORY_PREVIEW_SOUND_PLAYER_STATE_PLAYING = 2,
  DORY_PREVIEW_SOUND_PLAYER_STATE_DONE    = 3,
  DORY_PREVIEW_SOUND_PLAYER_STATE_ERROR   = 4
} DoryPreviewSoundPlayerState;

struct _DoryPreviewSoundPlayer
{
  GObject parent_instance;

  DoryPreviewSoundPlayerPrivate *priv;
};

struct _DoryPreviewSoundPlayerClass
{
  GObjectClass parent_class;
};

GType    dory_preview_sound_player_get_type     (void) G_GNUC_CONST;

G_END_DECLS

#endif /* __DORY_PREVIEW_SOUND_PLAYER_H__ */

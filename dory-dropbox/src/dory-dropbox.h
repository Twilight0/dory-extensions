/*
 * Copyright 2008 Evenflow, Inc.
 *
 * dory-dropbox.h
 * Header file for dory-dropbox.c
 *
 * This file is part of dory-dropbox.
 *
 * dory-dropbox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * dory-dropbox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with dory-dropbox.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef DORY_DROPBOX_H
#define DORY_DROPBOX_H

#include <glib.h>
#include <glib-object.h>

#include <libdory-extension/dory-info-provider.h>

#include "dropbox-command-client.h"
#include "dory-dropbox-hooks.h"
#include "dropbox-client.h"

G_BEGIN_DECLS

/* Declarations for the dropbox extension object.  This object will be
 * instantiated by dory.  It implements the GInterfaces 
 * exported by libdory. */

#define DORY_TYPE_DROPBOX	  (dory_dropbox_get_type ())
#define DORY_DROPBOX(o)	  (G_TYPE_CHECK_INSTANCE_CAST ((o), DORY_TYPE_DROPBOX, DoryDropbox))
#define DORY_IS_DROPBOX(o)	  (G_TYPE_CHECK_INSTANCE_TYPE ((o), DORY_TYPE_DROPBOX))
typedef struct _DoryDropbox      DoryDropbox;
typedef struct _DoryDropboxClass DoryDropboxClass;

struct _DoryDropbox {
  GObject parent_slot;
  GHashTable *filename2obj;
  GHashTable *obj2filename;
  GMutex *emblem_paths_mutex;
  GHashTable *emblem_paths;
  DropboxClient dc;
};

struct _DoryDropboxClass {
	GObjectClass parent_slot;
};

GType dory_dropbox_get_type(void);
void  dory_dropbox_register_type(GTypeModule *module);

extern gboolean dropbox_use_dory_submenu_workaround;
extern gboolean dropbox_use_operation_in_progress_workaround;

G_END_DECLS

#endif

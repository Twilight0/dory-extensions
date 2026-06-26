/* dory-share -- Dory File Sharing Extension
 *
 * Sebastien Estienne <sebastien.estienne@gmail.com>
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
 * Foundation, Inc., 51 Franklin Street - Suite 500, Boston, MA 02110-1335, USA.
 *
 * (C) Copyright 2005 Ethium, Inc.
 */

#ifndef DORY_SHARE_H
#define DORY_SHARE_H

#include <glib-object.h>

G_BEGIN_DECLS

/* Declarations for the Share extension object.  This object will be
 * instantiated by dory.  It implements the GInterfaces
 * exported by libdory. */


typedef struct _DoryShare      DoryShare;
typedef struct _DoryShareClass DoryShareClass;

struct _DoryShare {
	GObject parent_slot;
};

struct _DoryShareClass {
	GObjectClass parent_slot;

	/* No extra class members */
};


typedef struct _DoryShareData      DoryShareData;

struct _DoryShareData {
  gchar		*fullpath;
  gchar		*section;
  DoryFileInfo *fileinfo;
};

G_END_DECLS

typedef enum {
  DORY_SHARE_NOT_SHARED,
  DORY_SHARE_SHARED_RO,
  DORY_SHARE_SHARED_RW
} DoryShareStatus;

#endif
 

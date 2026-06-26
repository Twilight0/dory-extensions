/*
 *  dory-image-rotator.h
 * 
 *  Copyright (C) 2004-2006 Jürg Billeter
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *  Author: Jürg Billeter <j@bitron.ch>
 * 
 */

#ifndef DORY_IMAGE_ROTATOR_H
#define DORY_IMAGE_ROTATOR_H

#include <glib-object.h>

G_BEGIN_DECLS

#define DORY_TYPE_IMAGE_ROTATOR         (dory_image_rotator_get_type ())
#define DORY_IMAGE_ROTATOR(o)           (G_TYPE_CHECK_INSTANCE_CAST ((o), DORY_TYPE_IMAGE_ROTATOR, DoryImageRotator))
#define DORY_IMAGE_ROTATOR_CLASS(k)     (G_TYPE_CHECK_CLASS_CAST((k), DORY_TYPE_IMAGE_ROTATOR, DoryImageRotatorClass))
#define DORY_IS_IMAGE_ROTATOR(o)        (G_TYPE_CHECK_INSTANCE_TYPE ((o), DORY_TYPE_IMAGE_ROTATOR))
#define DORY_IS_IMAGE_ROTATOR_CLASS(k)  (G_TYPE_CHECK_CLASS_TYPE ((k), DORY_TYPE_IMAGE_ROTATOR))
#define DORY_IMAGE_ROTATOR_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), DORY_TYPE_IMAGE_ROTATOR, DoryImageRotatorClass))

typedef struct _DoryImageRotator DoryImageRotator;
typedef struct _DoryImageRotatorClass DoryImageRotatorClass;

struct _DoryImageRotator {
	GObject parent;
};

struct _DoryImageRotatorClass {
	GObjectClass parent_class;
	/* Add Signal Functions Here */
};

GType dory_image_rotator_get_type (void);
DoryImageRotator *dory_image_rotator_new (GList *files);
void dory_image_rotator_show_dialog (DoryImageRotator *dialog);

G_END_DECLS

#endif /* DORY_IMAGE_ROTATOR_H */

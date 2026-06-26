/*
 *  dory-image-converter.c
 * 
 *  Copyright (C) 2004-2005 Jürg Billeter
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

#ifdef HAVE_CONFIG_H
 #include <config.h> /* for GETTEXT_PACKAGE */
#endif

#include "dory-image-converter.h"
#include "dory-image-resizer.h"
#include "dory-image-rotator.h"

#include <libdory-extension/dory-menu-provider.h>
#include <libdory-extension/dory-name-and-desc-provider.h>

#include <glib/gi18n-lib.h>
#include <gtk/gtk.h>

#include <string.h> /* for strcmp */

static void dory_image_converter_instance_init (DoryImageConverter      *img);
static void dory_image_converter_class_init    (DoryImageConverterClass *class);
GList *     dory_image_converter_get_file_items (DoryMenuProvider *provider,
						     GtkWidget            *window,
						     GList                *files);

static GType image_converter_type = 0;

static gboolean
image_converter_file_is_image (DoryFileInfo *file_info)
{
	gchar            *uri_scheme;
	gchar            *mime_type;
	gboolean	maybe_image;
	
	maybe_image = TRUE;
	uri_scheme = dory_file_info_get_uri_scheme (file_info);
	if (strcmp (uri_scheme, "file") != 0)
		maybe_image = FALSE;
	g_free (uri_scheme);

	mime_type = dory_file_info_get_mime_type (file_info);
	if (strncmp (mime_type, "image/", 6) != 0)
		maybe_image = FALSE;
	g_free (mime_type);
	
	return maybe_image;
}

static GList *
image_converter_filter_images (GList *files)
{
	GList *images;
	GList *file;
	
	images = NULL;
	
	for (file = files; file != NULL; file = file->next) {
		if (image_converter_file_is_image (file->data))
			images = g_list_prepend (images, file->data);
	}
	
	return images;
}

static void
image_resize_callback (DoryMenuItem *item,
			GList *files)
{
	DoryImageResizer *resizer = dory_image_resizer_new (image_converter_filter_images (files));
	dory_image_resizer_show_dialog (resizer);
}

static void
image_rotate_callback (DoryMenuItem *item,
			GList *files)
{
	DoryImageRotator *rotator = dory_image_rotator_new (image_converter_filter_images (files));
	dory_image_rotator_show_dialog (rotator);
}

static GList *
dory_image_converter_get_background_items (DoryMenuProvider *provider,
					     GtkWidget		  *window,
					     DoryFileInfo	  *file_info)
{
	return NULL;
}

GList *
dory_image_converter_get_file_items (DoryMenuProvider *provider,
				       GtkWidget            *window,
				       GList                *files)
{
	DoryMenuItem *item;
	GList *file;
	GList *items = NULL;
	
	for (file = files; file != NULL; file = file->next) {
		if (image_converter_file_is_image (file->data)) {
			item = dory_menu_item_new ("DoryImageConverter::resize",
				        _("_Resize Images..."),
				        _("Resize each selected image"),
				       NULL);
			g_signal_connect (item, "activate",
					  G_CALLBACK (image_resize_callback),
					  dory_file_info_list_copy (files));
					
			items = g_list_prepend (items, item);

			item = dory_menu_item_new ("DoryImageConverter::rotate",
				        _("Ro_tate Images..."),
				        _("Rotate each selected image"),
				       NULL);
			g_signal_connect (item, "activate",
					  G_CALLBACK (image_rotate_callback),
					  dory_file_info_list_copy (files));

			items = g_list_prepend (items, item);
			
			items = g_list_reverse (items);

			return items;
		}
	}
	
	return NULL;
}

static GList *
dory_image_converter_get_name_and_desc (DoryNameAndDescProvider *provider) {
    GList *ret = NULL;
    gchar *string = g_strdup_printf ("dory-image-converter:::%s",
      _("Allows image resizing and rotation from the context menu"));
    ret = g_list_append (ret, (string));

    return ret;
}

static void
dory_image_converter_menu_provider_iface_init (DoryMenuProviderIface *iface)
{
	iface->get_background_items = dory_image_converter_get_background_items;
	iface->get_file_items = dory_image_converter_get_file_items;
}

static void
dory_image_converter_nd_provider_iface_init (DoryNameAndDescProviderIface *iface) {
	iface->get_name_and_desc = dory_image_converter_get_name_and_desc;
}

static void
dory_image_converter_instance_init (DoryImageConverter *img)
{
}

static void
dory_image_converter_class_init (DoryImageConverterClass *class)
{
}

GType
dory_image_converter_get_type (void) 
{
	return image_converter_type;
}

void
dory_image_converter_register_type (GTypeModule *module)
{
	static const GTypeInfo info = {
		sizeof (DoryImageConverterClass),
		(GBaseInitFunc) NULL,
		(GBaseFinalizeFunc) NULL,
		(GClassInitFunc) dory_image_converter_class_init,
		NULL, 
		NULL,
		sizeof (DoryImageConverter),
		0,
		(GInstanceInitFunc) dory_image_converter_instance_init,
	};

	static const GInterfaceInfo menu_provider_iface_info = {
		(GInterfaceInitFunc) dory_image_converter_menu_provider_iface_init,
		NULL,
		NULL
	};

	static const GInterfaceInfo nd_provider_iface_info = {
		(GInterfaceInitFunc) dory_image_converter_nd_provider_iface_init,
		NULL,
		NULL
	};


	image_converter_type = g_type_module_register_type (module,
						     G_TYPE_OBJECT,
						     "DoryImageConverter",
						     &info, 0);

	g_type_module_add_interface (module,
				     image_converter_type,
				     DORY_TYPE_MENU_PROVIDER,
				     &menu_provider_iface_info);

	g_type_module_add_interface (module,
                                     image_converter_type,
                                     DORY_TYPE_NAME_AND_DESC_PROVIDER,
                                     &nd_provider_iface_info);
}

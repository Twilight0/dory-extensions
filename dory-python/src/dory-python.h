/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*- */
/*
 *  Copyright (C) 2004,2005 Johan Dahlin
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef DORY_PYTHON_H
#define DORY_PYTHON_H

#include <glib-object.h>
#include <glib/gprintf.h>
#include <Python.h>

typedef enum {
    DORY_PYTHON_DEBUG_MISC = 1 << 0,
} DoryPythonDebug;

extern DoryPythonDebug dory_python_debug;

#define debug(x) { if (dory_python_debug & DORY_PYTHON_DEBUG_MISC) \
                       g_printf( "dory-python:" x "\n"); }
#define debug_enter()  { if (dory_python_debug & DORY_PYTHON_DEBUG_MISC) \
                             g_printf("%s: entered\n", __FUNCTION__); }
#define debug_enter_args(x, y) { if (dory_python_debug & DORY_PYTHON_DEBUG_MISC) \
                                     g_printf("%s: entered " x "\n", __FUNCTION__, y); }

extern PyTypeObject *_PyGtkWidget_Type;
#define PyGtkWidget_Type (*_PyGtkWidget_Type)

extern PyTypeObject *_PyDoryColumn_Type;
#define PyDoryColumn_Type (*_PyDoryColumn_Type)

extern PyTypeObject *_PyDoryColumnProvider_Type;
#define PyDoryColumnProvider_Type (*_PyDoryColumnProvider_Type)

extern PyTypeObject *_PyDoryInfoProvider_Type;
#define PyDoryInfoProvider_Type (*_PyDoryInfoProvider_Type)

extern PyTypeObject *_PyDoryLocationWidgetProvider_Type;
#define PyDoryLocationWidgetProvider_Type (*_PyDoryLocationWidgetProvider_Type)

extern PyTypeObject *_PyDoryNameAndDescProvider_Type;
#define PyDoryNameAndDescProvider_Type (*_PyDoryNameAndDescProvider_Type)

extern PyTypeObject *_PyDoryMenu_Type;
#define PyDoryMenu_Type (*_PyDoryMenu_Type)

extern PyTypeObject *_PyDoryMenuItem_Type;
#define PyDoryMenuItem_Type (*_PyDoryMenuItem_Type)

extern PyTypeObject *_PyDoryMenuProvider_Type;
#define PyDoryMenuProvider_Type (*_PyDoryMenuProvider_Type)

extern PyTypeObject *_PyDoryPropertyPage_Type;
#define PyDoryPropertyPage_Type (*_PyDoryPropertyPage_Type)

extern PyTypeObject *_PyDoryPropertyPageProvider_Type;
#define PyDoryPropertyPageProvider_Type (*_PyDoryPropertyPageProvider_Type)

extern PyTypeObject *_PyDoryOperationHandle_Type;
#define PyDoryOperationHandle_Type (*_PyDoryOperationHandle_Type)

#endif /* DORY_PYTHON_H */

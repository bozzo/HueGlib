/*
 * HueLight.h
 *
 * This file is part of HueGlib.
 *
 * HueGlib is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HueGlib is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HueGlib. If not, see <http://www.gnu.org/licenses/>.
 *
 * Created on 10 oct. 2013
 * By bozzo
 *
 **/

#ifndef HUELIGHT_H_
#define HUELIGHT_H_


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <glib.h>
#include <gio/gio.h>
#include <glib-object.h>

typedef struct _HueLight HueLight;
typedef struct _HueLightClass HueLightClass;
typedef struct _HueLightPrivate HueLightPrivate;

#define HUE_LIGHTOBJ_TYPE 				(hue_light_object_get_type ())
#define HUE_LIGHTOBJ_CLASS(klass) 		(G_TYPE_CHECK_CLASS_CAST ((klass), HUE_LIGHTOBJ_TYPE, HueLight))
#define HUE_LIGHTOBJ_GET_PRIVATE(obj) 	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), HUE_LIGHTOBJ_TYPE, HueLightPrivate))

#define HUE_LIGHTOBJ(obj)					(G_TYPE_CHECK_INSTANCE_CAST ((obj), HUE_LIGHTOBJ_TYPE, HueLight))
#define IS_HUE_LIGHTOBJ(obj)              (G_TYPE_CHECK_INSTANCE_TYPE ((obj), HUE_LIGHTOBJ_TYPE))
#define IS_HUE_LIGHTOBJ_CLASS(klass)      (G_TYPE_CHECK_CLASS_TYPE ((klass), HUE_LIGHTOBJ_TYPE))
#define HUE_LIGHTOBJ_GET_CLASS(obj)       (G_TYPE_INSTANCE_GET_CLASS ((obj), HUE_LIGHTOBJ_TYPE, HueLightClass))

GType hue_light_get_type (void);


struct _HueLightPrivate
{
	guint id;
	gchar * name;
};

struct _HueLight
{
	GObject parent;

	/*< private >*/
	HueLightPrivate * priv;
};

struct _HueLightClass
{
	GObjectClass parent;
};

/*
 * Methods definition
 */
gchar * hue_light_getName(HueLight * obj);
gboolean hue_light_setName(HueLight * obj, gchar * name);

gchar * hue_light_getId(HueLight * obj);
gboolean hue_light_setId(HueLight * obj, guint id);

#endif /* HUELIGHT_H_ */

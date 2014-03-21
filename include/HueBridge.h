/*
 * HueBridge.h
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

#ifndef HUEBRIDGE_H_
#define HUEBRIDGE_H_

#include <stdlib.h>
#include <glib-object.h>
#include <stdio.h>
#include <string.h>
#include <glib.h>
#include <gio/gio.h>
#include <netdb.h>
#include <json-glib/json-glib.h>

typedef struct _HueBridge HueBridge;
typedef struct _HueBridgeClass HueBridgeClass;
typedef struct _HueBridgePrivate HueBridgePrivate;

#define HUE_BRIDGE_TYPE 				(hue_bridge_get_type ())
#define HUE_BRIDGE_CLASS(klass) 		(G_TYPE_CHECK_CLASS_CAST ((klass), HUE_BRIDGE_TYPE, HueBridge))
#define HUE_BRIDGE_GET_PRIVATE(obj) 	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), HUE_BRIDGE_TYPE, HueBridgePrivate))

#define HUE_BRIDGE(obj)					(G_TYPE_CHECK_INSTANCE_CAST ((obj), HUE_BRIDGE_TYPE, HueBridge))
#define IS_HUE_BRIDGE(obj)              (G_TYPE_CHECK_INSTANCE_TYPE ((obj), HUE_BRIDGE_TYPE))
#define IS_HUE_BRIDGE_CLASS(klass)      (G_TYPE_CHECK_CLASS_TYPE ((klass), HUE_BRIDGE_TYPE))
#define HUE_BRIDGE_GET_CLASS(obj)       (G_TYPE_INSTANCE_GET_CLASS ((obj), HUE_BRIDGE_TYPE, HueBridgeClass))

GType hue_bridge_get_type (void);


struct _HueBridgePrivate
{
	gchar * username;
};

struct _HueBridge
{
	GObject parent;

	/*< private >*/
	HueBridgePrivate * priv;
};

struct _HueBridgeClass
{
	GObjectClass parent;
};

/*
 * Getters & setters
 */
gchar *  hue_bridge_get_username(HueBridge * obj);
gboolean hue_bridge_set_username(HueBridge * obj, gchar * username);

/*
 * Methods definition
 */

/* Users */
gboolean hue_bridge_create_user(HueBridge * obj, gchar * deviceType);
gboolean hue_bridge_delete_user(HueBridge * obj, gchar * username);

/* Config */
gboolean hue_bridge_get_config(HueBridge * obj);
gboolean hue_bridge_modify_config(HueBridge * obj, gchar * key, gchar * value);
gboolean hue_bridge_modify_config_set(HueBridge * obj, Glist * params);
gboolean hue_bridge_get_datastore(HueBridge * obj);

#endif /* HUEBRIDGE_H_ */

/*
 * HueUser.h
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

#ifndef HUEUSER_H_
#define HUEUSER_H_

#include <stdlib.h>
#include <glib-object.h>
#include <stdio.h>
#include <string.h>
#include <glib.h>
#include <gio/gio.h>
#include <netdb.h>
#include <json-glib/json-glib.h>

typedef struct _HueUser HueUser;
typedef struct _HueUserClass HueUserClass;
typedef struct _HueUserPrivate HueUserPrivate;

#define HUE_USER_TYPE 				(hue_user_get_type ())
#define HUE_USER_CLASS(klass) 		(G_TYPE_CHECK_CLASS_CAST ((klass), HUE_USER_TYPE, HueUser))
#define HUE_USER_GET_PRIVATE(obj) 	(G_TYPE_INSTANCE_GET_PRIVATE ((obj), HUE_USER_TYPE, HueUserPrivate))

#define HUE_USER(obj)					(G_TYPE_CHECK_INSTANCE_CAST ((obj), HUE_USER_TYPE, HueUser))
#define IS_HUE_USER(obj)              (G_TYPE_CHECK_INSTANCE_TYPE ((obj), HUE_USER_TYPE))
#define IS_HUE_USER_CLASS(klass)      (G_TYPE_CHECK_CLASS_TYPE ((klass), HUE_USER_TYPE))
#define HUE_USER_GET_CLASS(obj)       (G_TYPE_INSTANCE_GET_CLASS ((obj), HUE_USER_TYPE, HueUserClass))

GType hue_user_get_type (void);

static void hue_user_interface_init (JsonSerializableIface * iface);

struct _HueUserPrivate
{
	gchar * id;
	gchar * name;
	GDateTime * last_use;
	GDateTime * create_date;
};

struct _HueUser
{
	GObject parent;

	/*< private >*/
	HueUserPrivate * priv;
};

struct _HueUserClass
{
	GObjectClass parent;
};

/* Interface implementation */
JsonNode * hue_user_serialize_property (JsonSerializable * serializable, const gchar * property_name, const GValue * value, GParamSpec * pspec);
gboolean hue_user_deserialize_property (JsonSerializable * serializable, const gchar * property_name, GValue * value, GParamSpec * pspec, JsonNode * property_node);
GParamSpec * hue_user_find_property (JsonSerializable * serializable, const char * name);
GParamSpec ** hue_user_list_properties (JsonSerializable * serializable, guint * n_pspecs);
void hue_user_set_property (JsonSerializable * serializable, GParamSpec * pspec, const GValue * value);
void hue_user_get_property (JsonSerializable * serializable, GParamSpec * pspec, GValue * value);


/*
 * Getters & setters
 */
/* id */
gchar *  hue_user_get_id(HueUser * obj);
gboolean hue_user_set_id(HueUser * obj, gchar * id);
/* name */
gchar *  hue_user_get_name(HueUser * obj);
gboolean hue_user_set_name(HueUser * obj, gchar * name);
/* last_use_date */
GDateTime *  hue_user_get_last_use(HueUser * obj);
gboolean hue_user_set_last_use(HueUser * obj, GDateTime * last_use);
/* id */
GDateTime *  hue_user_get_create_date(HueUser * obj);
gboolean hue_user_set_create_date(HueUser * obj, GDateTime * create_date);

/*
 * Methods definition
 */
gboolean hue_user_parse_json(HueUser * obj,);


#endif /* HUEUSER_H_ */

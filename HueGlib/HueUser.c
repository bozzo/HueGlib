/*
 * HueUser.c
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
 * Created on 21 mars 2014
 * By bozzo
 *
 **/

#include "HueUser.h"

G_DEFINE_TYPE_WITH_CODE (HueUser, hue_user, G_TYPE_OBJECT, G_IMPLEMENT_INTERFACE (JSON_TYPE_SERIALIZABLE, hue_user_interface_init))

static void hue_user_interface_init (JsonSerializableIface * iface)
{
	iface->serialize_property=hue_user_serialize_property;
	iface->deserialize_property=hue_user_deserialize_property;
	iface->find_property=hue_user_find_property;
	iface->list_properties=hue_user_list_properties;
	iface->set_property=hue_user_set_property;
	iface->get_property=hue_user_get_property;
}

JsonNode * hue_user_serialize_property (JsonSerializable * serializable, const gchar * property_name, const GValue * value, GParamSpec * pspec)
{
	return NULL;
}

gboolean hue_user_deserialize_property (JsonSerializable * serializable, const gchar * property_name, GValue * value, GParamSpec * pspec, JsonNode * property_node)
{
	return FALSE;
}

GParamSpec * hue_user_find_property (JsonSerializable * serializable, const char * name)
{
	return NULL;
}

GParamSpec ** hue_user_list_properties (JsonSerializable * serializable, guint * n_pspecs)
{
	return NULL;
}

void hue_user_set_property (JsonSerializable * serializable, GParamSpec * pspec, const GValue * value)
{

}

void hue_user_get_property (JsonSerializable * serializable, GParamSpec * pspec, GValue * value)
{

}

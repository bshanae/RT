#include "gui_material.h"

void 				gui_material_prepare
					(t_gui_material *material, t_object *object)
{
	UINT			flag;

	flag = !(object_flag_get(object) & RT_OBJECT_PAIR);
	gtk_widget_set_sensitive(GTK_WIDGET(material->switcher_stack), flag);
	gtk_widget_set_sensitive(GTK_WIDGET(material->stack), flag);
	if (object_flag_get(object) & RT_OBJECT_LIGHT)
		gui_material_special_disable(material);
	else
		gui_material_special_enable(material);
	if (object_flag_get(object) & RT_OBJECT_HAS_TEXTURE)
		gui_material_texture_enable(material);
	else
		gui_material_texture_disable(material);
	gui_material_switch_mod(material, object->texture_id == -1 ?
		gui_material_material : gui_material_texture);
}
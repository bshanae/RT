#include "gui_material.h"

void 				gui_material_switch_mod
					(t_gui_material *material, t_gui_material_mod mod)
{
	if (mod == material->current_mod)
		return ;
	material->current_mod = mod;
	if (mod == gui_material_material)
		gtk_stack_set_visible_child_name(material->stack, "material");
	else if (mod == gui_material_texture)
		gtk_stack_set_visible_child_name(material->stack, "texture");
}
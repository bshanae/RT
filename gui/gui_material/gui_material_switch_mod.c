#include "gui_material.h"

void 				gui_material_switch_mod
					(t_gui_material *material, t_gui_material_mod mod)
{
	if (mod == material->current_mod)
		return ;
	material->current_mod = mod;
	material->switcher_block = rt_true;
	if (mod == gui_material_material)
	{
		gtk_stack_set_visible_child_name(material->stack, "material");
		gtk_toggle_button_set_active(material->switcher_material, TRUE);
		gtk_toggle_button_set_active(material->switcher_texture, FALSE);
	}
	else if (mod == gui_material_texture)
	{
		gtk_stack_set_visible_child_name(material->stack, "texture");
		gtk_toggle_button_set_active(material->switcher_material, FALSE);
		gtk_toggle_button_set_active(material->switcher_texture, TRUE);
	}
	material->switcher_block = rt_false;
}
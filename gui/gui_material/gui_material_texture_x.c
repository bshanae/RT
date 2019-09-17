#include "gui_material.h"

void 					gui_material_texture_enable(t_gui_material *material)
{
	material->texture_state = rt_on;
	gtk_stack_set_visible_child_name(material->switcher_stack, "show");
}

void 					gui_material_texture_disable(t_gui_material *material)
{
	material->texture_state = rt_off;
	gtk_stack_set_visible_child_name(material->switcher_stack, "hide");
	gui_material_switch_mod(material, gui_material_material);
}
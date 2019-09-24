#include "gui_material.h"

void 				gui_material_hide(t_gui_material *material)
{
	gtk_stack_set_visible_child_name(material->switcher_stack, "hide");
	gtk_stack_set_visible_child_name(material->stack, "hide");
}
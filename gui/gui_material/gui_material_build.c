#include "gui_material.h"

void 				gui_material_build
					(t_gui_material *gui, t_material *material)
{
	material->color.x = gui_entry_get_f(gui->color_r);
	material->color.y = gui_entry_get_f(gui->color_g);
	material->color.z = gui_entry_get_f(gui->color_b);
	material->color.w = 1.;
	material->emission.x = gui_entry_get_f(gui->emission_r);
	material->emission.y = gui_entry_get_f(gui->emission_g);
	material->emission.z = gui_entry_get_f(gui->emission_b);
	material->emission.w = 1.;
}

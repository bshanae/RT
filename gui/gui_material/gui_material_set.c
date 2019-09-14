#include "gui_material.h"

static RT_F			static_bound(RT_F value)
{
	if (value < (RT_F)0.)
		return ((RT_F)0.);
	if (value > (RT_F)1.)
		return (RT_F)1.;
	return (value);
}

void 				gui_material_set
					(t_gui_material *gui, t_material *material)
{
	material->color.x = static_bound(gui_entry_get_f(gui->color_r));
	material->color.y = static_bound(gui_entry_get_f(gui->color_g));
	material->color.z = static_bound(gui_entry_get_f(gui->color_b));
	material->color.w = 1.;
	material->emission.x = static_bound(gui_entry_get_f(gui->emission_r));
	material->emission.y = static_bound(gui_entry_get_f(gui->emission_g));
	material->emission.z = static_bound(gui_entry_get_f(gui->emission_b));
	material->emission.w = 1.;
}

#include "gui_material.h"

void 				gui_material_show
					(t_gui_material *gui, t_material *material)
{
	t_gui_color		color;
	t_gui_color		emission;

	color = gui_color_from_f4(&material->color);
	emission = gui_color_from_f4(&material->emission);
	gtk_color_button_set_rgba(gui->color_button, &color);
	gui_entry_set_f(gui->color_r, color.red);
	gui_entry_set_f(gui->color_g, color.green);
	gui_entry_set_f(gui->color_b, color.blue);
	gtk_color_button_set_rgba(gui->emission_button, &emission);
	gui_entry_set_f(gui->emission_r, emission.red);
	gui_entry_set_f(gui->emission_g, emission.green);
	gui_entry_set_f(gui->emission_b, emission.blue);
}
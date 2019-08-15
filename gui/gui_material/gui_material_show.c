#include "gui_material.h"

void 				gui_material_show
					(t_gui_material *gui, t_material *material)
{
	t_gui_color		color;

	color = gui_color_from_f4(&material->color);
	gtk_color_button_set_rgba(gui->color, &color);
	color = gui_color_from_f4(&material->emission);
	gtk_color_button_set_rgba(gui->emission, &color);
}
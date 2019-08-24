#include "gui_material.h"

void 				gui_material_build
					(t_gui_material *gui, t_material *material)
{
	t_gui_color		color;

	gtk_color_button_get_rgba(GTK_COLOR_BUTTON(gui->color), &color);
	material->color = gui_color_to_f4(&color);
	gtk_color_button_get_rgba(GTK_COLOR_BUTTON(gui->emission), &color);
	material->emission = gui_color_to_f4(&color);
}

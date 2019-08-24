#include "gui_material.h"

t_gui_material		gui_material_set
					(const t_gui_init_material *init, GtkBuilder *builder)
{
	t_gui_material	material;

	material.color = GTK_COLOR_BUTTON(RT_GUI_GET(builder, init->color));
	material.emission = GTK_COLOR_BUTTON(RT_GUI_GET(builder, init->emission));
	return (material);
}
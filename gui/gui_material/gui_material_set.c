#include "gui_material.h"

t_gui_material		gui_material_set
					(const t_gui_init_material *init, GtkBuilder *builder)
{
	t_gui_material	material;

	material.color_r = GTK_ENTRY(RT_GUI_GET(builder, init->color_r));
	material.color_g = GTK_ENTRY(RT_GUI_GET(builder, init->color_g));
	material.color_b = GTK_ENTRY(RT_GUI_GET(builder, init->color_b));
	material.color_button =
		GTK_COLOR_BUTTON(RT_GUI_GET(builder, init->color_button));
	material.emission_r = GTK_ENTRY(RT_GUI_GET(builder, init->emission_r));
	material.emission_g = GTK_ENTRY(RT_GUI_GET(builder, init->emission_g));
	material.emission_b = GTK_ENTRY(RT_GUI_GET(builder, init->emission_b));
	material.emission_button =
		GTK_COLOR_BUTTON(RT_GUI_GET(builder, init->emission_button));
	return (material);
}
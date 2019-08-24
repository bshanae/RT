#include "gui_material.h"

t_gui_material		gui_material_init
					(const t_gui_init_material *init, GtkBuilder *builder)
{
	t_gui_material	material;

	material.color_r = RT_GUI_GET(builder, init->color_r);
	material.color_g = RT_GUI_GET(builder, init->color_g);
	material.color_b = RT_GUI_GET(builder, init->color_b);
	material.color_button = RT_GUI_GET(builder, init->color_button);
	material.emission_r = RT_GUI_GET(builder, init->emission_r);
	material.emission_g = RT_GUI_GET(builder, init->emission_g);
	material.emission_b = RT_GUI_GET(builder, init->emission_b);
	material.emission_button = RT_GUI_GET(builder, init->emission_button);
	return (material);
}
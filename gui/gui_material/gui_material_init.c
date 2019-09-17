#include "gui_material.h"

t_gui_material		gui_material_init
					(const t_gui_init_material *init, GtkBuilder *builder)
{
	t_gui_material	material;

	material.switcher_stack = RT_GUI_GET(builder, init->switcher_stack);
	material.switcher_material = RT_GUI_GET(builder, init->switcher_material);
	material.switcher_texture = RT_GUI_GET(builder, init->switcher_texture);
	material.stack = RT_GUI_GET(builder, init->stack);
	material.color_r = RT_GUI_GET(builder, init->color_r);
	material.color_g = RT_GUI_GET(builder, init->color_g);
	material.color_b = RT_GUI_GET(builder, init->color_b);
	material.color_button = RT_GUI_GET(builder, init->color_button);
	material.color_box = RT_GUI_GET(builder, init->color_box);
	material.color_silent = 0;
	material.emission_r = RT_GUI_GET(builder, init->emission_r);
	material.emission_g = RT_GUI_GET(builder, init->emission_g);
	material.emission_b = RT_GUI_GET(builder, init->emission_b);
	material.emission_button = RT_GUI_GET(builder, init->emission_button);
	material.texture_state = rt_off;
	gui_material_switch_mod(&material, gui_material_material);
	return (material);
}
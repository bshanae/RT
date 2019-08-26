#include "gui_scene_add.h"

void					gui_scene_add_init_material
						(t_gui_scene_add *add, GtkBuilder *builder)
{
	t_gui_init_material	init;

	ft_strcpy(init.color_r, "scene_add_material_color_r");
	ft_strcpy(init.color_g, "scene_add_material_color_g");
	ft_strcpy(init.color_b, "scene_add_material_color_b");
	ft_strcpy(init.color_button, "scene_add_material_color_button");
	ft_strcpy(init.emission_button, "scene_add_material_emission_button");
	ft_strcpy(init.emission_r, "scene_add_material_emission_r");
	ft_strcpy(init.emission_g, "scene_add_material_emission_g");
	ft_strcpy(init.emission_b, "scene_add_material_emission_b");
	add->material = gui_material_init(&init, builder);
}
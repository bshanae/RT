#include "gui_scene_add.h"

void					gui_scene_add_set_material
						(t_gui_scene_add *add, GtkBuilder *builder)
{
	t_gui_init_material	init;

	ft_strcpy(init.color, "scene_add_material_color");
	ft_strcpy(init.emission, "scene_add_material_emission");
	add->material = gui_material_set(&init, builder);
}
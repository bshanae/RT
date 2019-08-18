#include "gui_scene_edit.h"

void 					gui_scene_edit_set_material
						(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_material	init;

	ft_strcpy(init.color, "scene_edit_material_color");
	ft_strcpy(init.emission, "scene_edit_material_emission");
	edit->material = gui_material_set(&init, builder);
}
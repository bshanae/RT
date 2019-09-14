#include "gui_scene_add.h"

void 				gui_scene_add_init_p_cube
					(t_gui_scene_add *add, GtkBuilder *builder)
{
	t_gui_init_p_cube			init;

	ft_strcpy(init.position_x, "object_add_perforated_cube_position_x");
	ft_strcpy(init.position_y, "object_add_perforated_cube_position_y");
	ft_strcpy(init.position_z, "object_add_perforated_cube_position_z");
	ft_strcpy(init.iterations, "object_add_perforated_cube_iterations");
	add->p_cube = gui_object_p_cube_init(&init, builder);
}
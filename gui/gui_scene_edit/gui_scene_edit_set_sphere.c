#include "gui_scene_edit.h"

void 					gui_scene_edit_set_sphere
						(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_sphere	init;

	ft_strcpy(init.box, "object_edit_sphere_box");
	ft_strcpy(init.position_x, "object_edit_sphere_position_x");
	ft_strcpy(init.position_y, "object_edit_sphere_position_y");
	ft_strcpy(init.position_z, "object_edit_sphere_position_z");
	ft_strcpy(init.radius, "object_edit_sphere_radius");
	edit->sphere = gui_object_sphere_set(&init, builder);
}

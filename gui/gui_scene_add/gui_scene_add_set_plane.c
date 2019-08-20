#include "gui_scene_add.h"

void 					gui_scene_add_set_plane
						(t_gui_scene_add *add, GtkBuilder *builder)
{
	t_gui_init_plane	init;

	ft_strcpy(init.box, "object_add_plane_box");
	ft_strcpy(init.offscreen , "object_add_plane_offscreen");
	ft_strcpy(init.name , "");
	ft_strcpy(init.position_x , "object_add_plane_position_x");
	ft_strcpy(init.position_y , "object_add_plane_position_y");
	ft_strcpy(init.position_z , "object_add_plane_position_z");
	ft_strcpy(init.normal_x , "object_add_plane_normal_x");
	ft_strcpy(init.normal_y , "object_add_plane_normal_y");
	ft_strcpy(init.normal_z , "object_add_plane_normal_z");
	add->plane = gui_object_plane_set(&init, builder);
	add->plane.name = add->name;
	gui_object_x_set((t_gui_object_x *) &add->plane, add->overlay);
}

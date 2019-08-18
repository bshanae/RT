#include "gui_scene_edit.h"

void 					gui_scene_edit_set_plane
						(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_plane	init;

	ft_strcpy(init.box, "object_edit_plane_box");
	ft_strcpy(init.offscreen , "object_edit_plane_offscreen");
	ft_strcpy(init.name , "object_edit_plane_name");
	ft_strcpy(init.position_x , "object_edit_plane_position_x");
	ft_strcpy(init.position_y , "object_edit_plane_position_y");
	ft_strcpy(init.position_z , "object_edit_plane_position_z");
	ft_strcpy(init.normal_x , "object_edit_plane_normal_x");
	ft_strcpy(init.normal_y , "object_edit_plane_normal_y");
	ft_strcpy(init.normal_z , "object_edit_plane_normal_z");
	edit->plane = gui_object_plane_set(&init, builder);
	gui_object_x_set((t_gui_object_x *) &edit->plane, edit->overlay);
}

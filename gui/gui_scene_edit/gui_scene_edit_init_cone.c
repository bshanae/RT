#include "gui_scene_edit.h"

void 					gui_scene_edit_init_cone
						(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_cone		init;

	ft_strcpy(init.top_x, "object_edit_cone_top_x");
	ft_strcpy(init.top_y, "object_edit_cone_top_y");
	ft_strcpy(init.top_z, "object_edit_cone_top_z");
	ft_strcpy(init.bottom_x, "object_edit_cone_bottom_x");
	ft_strcpy(init.bottom_y, "object_edit_cone_bottom_y");
	ft_strcpy(init.bottom_z, "object_edit_cone_bottom_z");
	ft_strcpy(init.radius, "object_edit_cone_radius");
	edit->cone = gui_object_cone_init(&init, builder);
}

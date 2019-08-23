#include "gui_scene_add.h"

void 					gui_scene_add_set_cone
						(t_gui_scene_add *add, GtkBuilder *builder)
{
	t_gui_init_cone		init;

	ft_strcpy(init.box, "object_add_cone_box");
	ft_strcpy(init.top_x, "object_add_cone_top_x");
	ft_strcpy(init.top_y, "object_add_cone_top_y");
	ft_strcpy(init.top_z, "object_add_cone_top_z");
	ft_strcpy(init.bottom_x, "object_add_cone_bottom_x");
	ft_strcpy(init.bottom_y, "object_add_cone_bottom_y");
	ft_strcpy(init.bottom_z, "object_add_cone_bottom_z");
	ft_strcpy(init.radius, "object_add_cone_radius");
	add->cone = gui_object_cone_set(&init, builder);
}

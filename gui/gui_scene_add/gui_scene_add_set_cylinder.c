#include "gui_scene_add.h"

void 					gui_scene_add_set_cylinder
						(t_gui_scene_add *add, GtkBuilder *builder)
{
	t_gui_init_cylinder	init;

	ft_strcpy(init.box, "object_add_cylinder_box");
	ft_strcpy(init.offscreen, "object_add_cylinder_offscreen");
	ft_strcpy(init.name, "");
	ft_strcpy(init.top_x, "object_add_cylinder_top_x");
	ft_strcpy(init.top_y, "object_add_cylinder_top_y");
	ft_strcpy(init.top_z, "object_add_cylinder_top_z");
	ft_strcpy(init.bottom_x, "object_add_cylinder_bottom_x");
	ft_strcpy(init.bottom_y, "object_add_cylinder_bottom_y");
	ft_strcpy(init.bottom_z, "object_add_cylinder_bottom_z");
	ft_strcpy(init.radius, "object_add_cylinder_radius");
	add->cylinder = gui_object_cylinder_set(&init, builder);
	add->cylinder.name = add->name;
	gui_object_x_set((t_gui_object_x *)&add->cylinder, add->overlay);
}

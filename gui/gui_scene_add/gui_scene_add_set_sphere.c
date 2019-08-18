#include "gui_scene_add.h"

void 					gui_scene_add_set_sphere
						(t_gui_scene_add *add, GtkBuilder *builder)
{
	t_gui_init_sphere	init;

	ft_strcpy(init.box, "object_add_sphere_box");
	ft_strcpy(init.offscreen, "object_add_sphere_offscreen");
	ft_strcpy(init.name, "");
	ft_strcpy(init.position_x, "object_add_sphere_position_x");
	ft_strcpy(init.position_y, "object_add_sphere_position_y");
	ft_strcpy(init.position_z, "object_add_sphere_position_z");
	ft_strcpy(init.radius, "object_add_sphere_radius");
	add->sphere = gui_object_sphere_set(&init, builder);
	add->sphere.name = add->name;
	gui_object_x_set((t_gui_object_x *) &add->sphere, add->overlay);
}

#include "gui_scene_edit.h"

void 							gui_scene_edit_init_explosion
								(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_explosion		init;

	ft_strcpy(init.position_x, "object_edit_explosion_position_x");
	ft_strcpy(init.position_y, "object_edit_explosion_position_y");
	ft_strcpy(init.position_z, "object_edit_explosion_position_z");
	ft_strcpy(init.radius, "object_edit_explosion_radius");
	ft_strcpy(init.noise, "object_edit_explosion_noise");
	edit->explosion = gui_object_explosion_init(&init, builder);
}
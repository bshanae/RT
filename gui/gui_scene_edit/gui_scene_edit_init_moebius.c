#include "gui_scene_edit.h"

void 							gui_scene_edit_init_moebius
								(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_moebius			init;

	ft_strcpy(init.position_x, "object_edit_moebius_position_x");
	ft_strcpy(init.position_y, "object_edit_moebius_position_y");
	ft_strcpy(init.position_z, "object_edit_moebius_position_z");
	ft_strcpy(init.radius, "object_edit_moebius_radius");
	ft_strcpy(init.width, "object_edit_moebius_width");
	edit->moebius = gui_object_moebius_init(&init, builder);
}

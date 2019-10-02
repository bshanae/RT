#include "gui_scene_edit.h"

void 							gui_scene_edit_init_limited
								(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_pair				init;

	ft_strcpy(init.first_combo, "object_edit_limited_main");
	ft_strcpy(init.second_combo, "object_edit_limited_limit");
	ft_strcpy(init.first_list, "scene_limited_main_list");
	ft_strcpy(init.second_list, "scene_limited_limit_list");
	edit->limited = gui_object_pair_init(&init, builder);
}
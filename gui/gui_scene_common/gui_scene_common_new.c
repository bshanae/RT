#include "gui_scene_common.h"

t_gui_scene_common		*gui_scene_common_new(GtkBuilder *builder)
{
	t_gui_scene_common	*new;

	new = malloc(sizeof(t_gui_scene_common));
	new->full = RT_GUI_GET(builder, "scene_list");
	new->limited_main = RT_GUI_GET(builder, "scene_limited_main_list");
	new->limited_limit = RT_GUI_GET(builder, "scene_limited_limit_list");
	new->csg = RT_GUI_GET(builder, "scene_csg_list");
	new->reset_generator = rt_false;
	return (new);
}
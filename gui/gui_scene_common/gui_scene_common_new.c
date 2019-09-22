#include "gui_scene_common.h"

t_gui_scene_common		*gui_scene_common_new(GtkBuilder *builder)
{
	t_gui_scene_common	*new;

	new = rt_malloc(sizeof(t_gui_scene_common));
	new->full = RT_GUI_GET(builder, "scene_list");
	new->limited_main = RT_GUI_GET(builder, "scene_limited_main_list");
	new->limited_limit = RT_GUI_GET(builder, "scene_limited_limit_list");
	new->csg = RT_GUI_GET(builder, "scene_csg_list");
	new->types = RT_GUI_GET(builder, "scene_type_list");
	new->textures = RT_GUI_GET(builder, "scene_texture_list");
	new->background = RT_GUI_GET(builder, "scene_background_list");
	new->reset_generator = rt_false;
	gui_scene_common_update_background(new);
	return (new);
}
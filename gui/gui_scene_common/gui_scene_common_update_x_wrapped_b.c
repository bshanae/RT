#include "gui_scene_common.h"

void				gui_scene_common_update_textures_wrapped
	(t_gui_scene_common *gui)
{
	gui_scene_common_update_wrap(gui, gui_scene_common_update_textures);
}

void				gui_scene_common_update_background_wrapped
	(t_gui_scene_common *gui)
{
	gui_scene_common_update_wrap(gui, gui_scene_common_update_background);
}

void				gui_scene_common_update_all_wrapped
	(t_gui_scene_common *gui)
{
	gui_scene_common_update_wrap(gui, gui_scene_common_update_all);
}
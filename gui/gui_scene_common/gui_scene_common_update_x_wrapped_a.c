#include "gui_scene_common.h"

void				gui_scene_common_update_full_wrapped
	(t_gui_scene_common *gui)
{
	gui_scene_common_update_wrap(gui, gui_scene_common_update_full);
}

void				gui_scene_common_update_limited_wrapped
	(t_gui_scene_common *gui)
{
	gui_scene_common_update_wrap(gui, gui_scene_common_update_limited);
}

void				gui_scene_common_update_csg_wrapped
	(t_gui_scene_common *gui)
{
	gui_scene_common_update_wrap(gui, gui_scene_common_update_csg);
}

void				gui_scene_common_update_types_wrapped
	(t_gui_scene_common *gui)
{
	gui_scene_common_update_wrap(gui, gui_scene_common_update_types);
}
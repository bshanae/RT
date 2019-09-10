#include "gui_scene_common.h"

void				gui_scene_common_delete(t_gui_scene_common **common)
{
	free(*common);
	*common = NULL;
}

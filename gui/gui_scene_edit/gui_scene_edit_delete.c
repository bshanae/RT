#include "gui_scene_edit.h"

void 				gui_scene_edit_delete(t_gui_scene_edit **object)
{
	free(*object);
	*object = NULL;
}
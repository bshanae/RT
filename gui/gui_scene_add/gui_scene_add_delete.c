#include "gui_scene_add.h"

void 				gui_scene_add_delete(t_gui_scene_add **object)
{
	free(*object);
	*object = NULL;
}
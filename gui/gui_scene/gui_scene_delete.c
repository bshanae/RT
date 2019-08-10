#include "gui_scene.h"

void 				gui_scene_delete(t_gui_scene **object)
{
	gui_scene_edit_delete(&(*object)->edit);
	gui_scene_add_delete(&(*object)->add);
	free(*object);
	*object = NULL;
}
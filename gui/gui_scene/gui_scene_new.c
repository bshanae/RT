#include "gui_scene.h"

t_gui_scene			*gui_scene_new(void)
{
	t_gui_scene		*new;

	new = malloc(sizeof(t_gui_scene));
	new->list = gui_scene_list_new();
	new->params = gui_scene_params_new();
	return (new);
}
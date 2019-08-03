#include "gui_scene_params.h"

t_gui_scene_params		*gui_scene_params_new(void)
{
	t_gui_scene_params	*new;

	new = malloc(sizeof(t_gui_scene_params));
	new->current = NULL;
	new->overlay = NULL;
	return (new);
}

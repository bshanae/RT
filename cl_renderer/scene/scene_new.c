#include "scene.h"

t_scene				*scene_new(void)
{
	t_scene			*new;

	new = malloc(sizeof(t_scene));
	new->objects_length = 0;
	scene_set_ids(new);
	return (new);
}
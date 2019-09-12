#include "scene.h"

t_scene				*scene_new(void)
{
	t_scene			*new;

	new = rt_malloc(sizeof(t_scene));
	texture_initialization(&new->texture);
	new->objects_length = 0;
	new->lights_length = 0;
	return (new);
}
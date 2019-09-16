#include "scene.h"

t_scene				*scene_new(UINT_REF mod_ptr)
{
	t_scene			*new;

	new = rt_malloc(sizeof(t_scene));
	texture_initialization(&new->texture);
	new->objects_length = 0;
	new->lights_length = 0;
	new->current_mod = mod_ptr;
	new->selected_id = -1;
	return (new);
}
#include "scene.h"

t_scene				*scene_new(void)
{
	t_scene			*new;

	new = malloc(sizeof(t_scene));
	new->objects_length = 0;
	new->lights_length = 0;
	//ft_bzero(new->textures, sizeof(t_texture *) * MAX_TEXTURES_NUMBER);
	return (new);
}
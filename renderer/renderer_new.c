#include "renderer.h"

t_renderer			*renderer_new(void)
{
	t_renderer		*new;

	new = malloc(sizeof(t_renderer));
	new->scene = scene_new();
	return (new);
}
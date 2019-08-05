#include "renderer.h"

t_renderer			*renderer_new(void)
{
	t_renderer		*new;

	new = malloc(sizeof(t_renderer));
	new->camera = camera_new();
	new->scene = scene_new();
	new->open_cl = open_cl_manager_new();
	return (new);
}
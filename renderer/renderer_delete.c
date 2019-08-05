#include "renderer.h"

void				renderer_delete(t_renderer **renderer)
{
	camera_delete(&(*renderer)->camera);
	scene_delete(&(*renderer)->scene);
	free(*renderer);
	*renderer = NULL;
}
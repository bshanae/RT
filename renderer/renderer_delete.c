#include "renderer.h"

void				renderer_delete(t_renderer **renderer)
{
	camera_delete(&(*renderer)->camera);
	scene_delete(&(*renderer)->scene);
	open_cl_manager_delete(&(*renderer)->open_cl);
	free(*renderer);
	*renderer = NULL;
}
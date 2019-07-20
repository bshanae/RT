#include "renderer.h"

void 				renderer_delete(t_renderer **renderer)
{
	sdl_ctrl_delete(&(*renderer)->sdl);
	camera_delete(&(*renderer)->camera);
	scene_delete(&(*renderer)->scene);
	free((*renderer)->sample_data);
	free(*renderer);
	*renderer = NULL;
}
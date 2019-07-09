#include "renderer.h"

void 				renderer_delete(t_renderer **renderer)
{
	sdl_ctrl_delete(&(*renderer)->sdl);
	camera_delete(&(*renderer)->camera);
	free(*renderer);
	*renderer = NULL;
}
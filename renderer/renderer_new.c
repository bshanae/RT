#include "renderer.h"

t_renderer			*renderer_new()
{
	t_renderer		*new;

	new = (t_renderer *)malloc(sizeof(t_renderer));
	new->sdl = sdl_ctrl_new();
	sdl_ctrl_init(new->sdl);
	new->camera = camera_new();
	new->scene = scene_new();
	new->sample_data = (t_vector3 *)malloc(sizeof(t_vector3) * WINDOW_WIDTH * WINDOW_HEIGHT);
	new->sample_number = 0;
	return (new);
}
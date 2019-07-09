#include "renderer.h"

t_renderer			*renderer_new()
{
	t_renderer		*new;

	new = (t_renderer *)malloc(sizeof(t_renderer));
	new->sdl = sdl_ctrl_new();
	sdl_ctrl_init(new->sdl);
	return (new);
}
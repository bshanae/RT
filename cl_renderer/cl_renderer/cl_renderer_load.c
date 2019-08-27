#include "cl_renderer.h"

void				cl_renderer_load
					(t_cl_renderer *renderer, const char *path)
{
	load_scene(renderer, path);
	scene_update(renderer->data.scene);
}
#include "cl_renderer.h"
#include "json.h"

void				cl_renderer_load
					(t_cl_renderer *renderer, const char *path)
{
	renderer_load(renderer, path);
	scene_update(renderer->data.scene);
}
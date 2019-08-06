#include "cl_renderer.h"

void				cl_renderer_init_context(t_cl_renderer *renderer)
{
	renderer->context =
		clCreateContext(NULL, 1, &renderer->device_id, 0, 0, &renderer->error);
	ft_assert(renderer->error == 0, "open_cl : context");
}
#include "cl_renderer.h"

void				cl_renderer_create_queue(t_cl_renderer *renderer)
{
	renderer->queue = clCreateCommandQueue(renderer->context,
		renderer->device_id, 0, &renderer->error);
	ft_assert(renderer->error == 0, "open_cl : queue creation");
	renderer->queue_length = renderer->image->width * renderer->image->height;
}
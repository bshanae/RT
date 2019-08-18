#include "cl_renderer.h"

void				cl_renderer_create_queue(t_cl_renderer *renderer)
{
	renderer->queue = clCreateCommandQueue(renderer->context,
		renderer->device_id, 0, &renderer->error);
	ASSERT(renderer->error == 0)
#ifdef RT_DEBUG
# ifdef RT_DEBUG_QUEUE_LENGTH
	renderer->queue_length = RT_DEBUG_QUEUE_LENGTH;
# else
	renderer->queue_length = renderer->image->width * 10;
# endif
#else
	renderer->queue_length = renderer->image->width * renderer->image->height;
#endif
}
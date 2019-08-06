#include "cl_renderer.h"

void				cl_renderer_render(t_cl_renderer *renderer)
{
	renderer->error = clEnqueueWriteBuffer(renderer->queue, renderer->data_device.camera,
		CL_TRUE, 0, renderer->data_size.camera, renderer->data_host.camera, 0, NULL, NULL);
	ASSERT(renderer->error == 0)
	renderer->error = clEnqueueWriteBuffer(renderer->queue, renderer->data_device.scene,
		CL_TRUE, 0, renderer->data_size.scene, renderer->data_host.scene, 0, NULL, NULL);
	ASSERT(renderer->error == 0)
	renderer->error = clEnqueueNDRangeKernel(renderer->queue, renderer->kernel,
		1, NULL, &renderer->queue_length, NULL, 0, NULL, NULL);
	ASSERT(renderer->error == 0)
	renderer->error = clEnqueueReadBuffer(renderer->queue, renderer->data_device.image, CL_TRUE,
		0, renderer->data_size.image, renderer->data_host.image, 0, NULL, NULL);
	ASSERT(renderer->error == 0)
}

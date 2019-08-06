#include "cl_renderer.h"

void				cl_renderer_set_arguments(t_cl_renderer *renderer)
{
	renderer->error = clSetKernelArg(renderer->kernel,
		0, sizeof(cl_mem), &renderer->data_device.camera);
	renderer->error += clSetKernelArg(renderer->kernel,
		1, sizeof(cl_mem), &renderer->data_device.scene);
	renderer->error += clSetKernelArg(renderer->kernel,
		2, sizeof(cl_mem), &renderer->data_device.image);
	ft_assert(renderer->error == 0, "open_cl : setting arguments");
}

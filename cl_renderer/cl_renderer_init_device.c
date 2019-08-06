#include "cl_renderer.h"

void				cl_renderer_init_device(t_cl_renderer *renderer)
{
	cl_platform_id	platform;

	renderer->error = clGetPlatformIDs(1, &platform, NULL);
	ft_assert(renderer->error == 0, "renderer : platform id");
	renderer->error = clGetDeviceIDs(platform,
		CL_DEVICE_TYPE_GPU, 1, &renderer->device_id, NULL);
	ft_assert(renderer->error == 0, "open_cl : device id");
}



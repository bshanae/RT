#include "cl_builder.h"

void				cl_builder_init_device(t_cl_builder *builder)
{
	cl_platform_id	platform;

	builder->error = clGetPlatformIDs(1, &platform, NULL);
	ASSERT(builder->error == 0)
	builder->error = clGetDeviceIDs(platform,
		CL_DEVICE_TYPE_GPU, 1, &builder->device_id, NULL);
	ASSERT(builder->error == 0)
}

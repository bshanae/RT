#include "cl_builder.h"

void				cl_builder_init_device(t_cl_builder *builder)
{
	cl_platform_id	platform;

	printf("Kernel Builder : Initializing device\n");
	builder->error = clGetPlatformIDs(1, &platform, NULL);
	ASSERT(builder->error == 0)
#ifdef RT_OPEN_CL_CPU
	builder->error = clGetDeviceIDs(platform,
		CL_DEVICE_TYPE_CPU, 1, &builder->device_id, NULL);
#elif defined RT_OPEN_CL_GPU
	builder->error = clGetDeviceIDs(platform,
		CL_DEVICE_TYPE_GPU, 1, &builder->device_id, NULL);
#endif
	ASSERT(builder->error == 0)
}

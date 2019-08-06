#include "open_cl_manager.h"

void				open_cl_manager_init_device(t_open_cl_manager *open_cl)
{
	cl_platform_id	platform;
	int				error;

	error = clGetPlatformIDs(1, &platform, NULL);
	ft_assert(error == 0, "open_cl : platform id");
	error = clGetDeviceIDs(platform,
		CL_DEVICE_TYPE_GPU, 1, &open_cl->device_id, NULL);
	ft_assert(error == 0, "open_cl : device id");
}



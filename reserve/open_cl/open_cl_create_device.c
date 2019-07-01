#include "open_cl.h"

void				open_cl_create_device(t_open_cl *me)
{
	cl_platform_id	platform;
	int				error;

	error = clGetPlatformIDs(1, &platform, NULL);
	error_check(__LINE__, __FUNCTION__, error);
	error =
		clGetDeviceIDs(platform, CL_DEVICE_TYPE_CPU, 1, &me->device_id, NULL);
	error_check(__LINE__, __FUNCTION__, error);
}
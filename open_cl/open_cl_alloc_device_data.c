#include "open_cl.h"

void				open_cl_alloc_device(t_open_cl *me)
{
	int 			error;

	me->data_device.image = clCreateBuffer(me->context,
		CL_MEM_WRITE_ONLY, me->data_size.image, NULL, &error);
	error_check(__LINE__, __FUNCTION__, error);
	me->data_device.scene = clCreateBuffer(me->context,
		CL_MEM_READ_ONLY, me->data_size.scene, NULL, &error);
	error_check(__LINE__, __FUNCTION__, error);
}
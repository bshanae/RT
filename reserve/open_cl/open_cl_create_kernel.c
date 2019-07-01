#include "open_cl.h"

void				open_cl_create_kernel(t_open_cl *me)
{
	int				error;

	me->kernel = clCreateKernel(me->program, CL_FUNCTION, &error);
	error_check(__LINE__, __FUNCTION__, error);
}

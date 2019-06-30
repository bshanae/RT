#include "open_cl.h"

void				open_cl_create_context(t_open_cl *me)
{
	int				error;

	me->context = clCreateContext(NULL, 1, &me->device_id, 0, 0, &error);
	error_check(__LINE__, __FUNCTION__, error);
}
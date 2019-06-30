#include "open_cl.h"

void				open_cl_create_queue(t_open_cl *me)
{
	int				error;

	me->queue = clCreateCommandQueue(me->context, me->device_id, 0, &error);
	error_check(__LINE__, __FUNCTION__, error);
}

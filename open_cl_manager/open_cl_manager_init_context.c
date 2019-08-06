#include "open_cl_manager.h"

void				open_cl_manager_init_context(t_open_cl_manager *open_cl)
{
	int				error;

	open_cl->context =
		clCreateContext(NULL, 1, &open_cl->device_id, 0, 0, &error);
	ft_assert(error == 0, "open_cl : context");
}
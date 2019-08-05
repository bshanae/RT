#include "open_cl_manager.h"

t_open_cl_manager		*open_cl_manager_new(void)
{
	t_open_cl_manager	*new;

	new = malloc(sizeof(t_open_cl_manager));
	return (new);
	cl_platform_id platform;
	int error = clGetPlatformIDs(1, &platform, NULL);
}

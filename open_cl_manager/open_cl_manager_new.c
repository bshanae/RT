#include "open_cl_manager.h"

t_open_cl_manager		*open_cl_manager_new(void)
{
	t_open_cl_manager	*new;

	new = malloc(sizeof(t_open_cl_manager));
	open_cl_manager_init_device(new);
	open_cl_manager_init_context(new);


//	open_cl_create_program(new);
//	open_cl_create_queue(new);
//	open_cl_create_kernel(new);


	return (new);
}

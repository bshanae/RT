#include "cl_builder.h"

t_cl_builder		*cl_builder_new(void)
{
	t_cl_builder	*new;

	new = (t_cl_builder *)malloc(sizeof(t_cl_builder));
	new->program = cl_program_new(CL_SOURCE_FOLDER);
	cl_builder_init_device(new);
	cl_builder_create_context(new);
	cl_builder_create_program(new);
	cl_builder_create_kernel(new);
	cl_builder_create_queue(new);
	return (new);
}
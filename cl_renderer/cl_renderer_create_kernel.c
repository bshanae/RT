#include "cl_renderer.h"

void				cl_renderer_create_kernel(t_cl_renderer *renderer)
{
	renderer->kernel = clCreateKernel(renderer->program.program,
		CL_MAIN_FUNCTION, &renderer->error);
	ft_assert(renderer->error == 0, "open_cl : kernel creation");
}
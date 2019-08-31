#include "cl_builder.h"

void				cl_builder_delete(t_cl_builder **builder)
{
#ifndef RT_OPEN_CL_DISABLED
	clReleaseDevice((*builder)->device_id);
	clReleaseContext((*builder)->context);
	clReleaseKernel((*builder)->kernel);
	clReleaseCommandQueue((*builder)->queue);
	cl_program_delete(&(*builder)->program);
#endif
	free(*builder);
	*builder = NULL;
}
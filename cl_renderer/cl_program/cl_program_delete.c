#include "cl_program.h"

void				cl_program_delete(t_cl_program **program)
{
	free((*program)->buffer);
	(*program)->buffer = NULL;
	(*program)->capacity = 0;
	(*program)->length = -1;
	clReleaseProgram((*program)->program);
	free(*program);
}
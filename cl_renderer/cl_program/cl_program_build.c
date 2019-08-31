#include "cl_program.h"

int					cl_program_build
					(t_cl_program *program, cl_context context, CHAR_REF flags)
{
	program->buffer[program->length] = '\0';
	program->program = clCreateProgramWithSource(context, 1,
		(const char **)&program->buffer, &program->length, &program->error);
	RT_ASSERT(program->error == 0)
	program->error =
		clBuildProgram(program->program, 0, NULL, flags, NULL, NULL);
	return (program->error != 0);
}

#include "cl_program.h"

t_cl_program		*cl_program_new(CHAR_REF path)
{
	t_cl_program	*new;

	new = (t_cl_program *)malloc(sizeof(t_cl_program));
	new->length = 0;
	new->capacity = RT_CL_PROGRAM_INIT;
	new->buffer = malloc(RT_CL_PROGRAM_INIT);
	ft_strcpy(new->path, path);
	return (new);
}
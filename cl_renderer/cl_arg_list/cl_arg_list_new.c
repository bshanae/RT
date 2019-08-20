#include "cl_arg_list.h"

t_cl_arg_list			*cl_arg_list_new
						(cl_context context, cl_command_queue queue)
{
	t_cl_arg_list	*new;

	new = (t_cl_arg_list *)malloc(sizeof(t_cl_arg_list));
	new->context = context;
	new->queue = queue;
	new->length = 0;
	return (new);
}
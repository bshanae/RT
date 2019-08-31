#include "cl_arg_list.h"

t_cl_arg_list			*cl_arg_list_new
						(cl_context context, cl_command_queue queue)
{
	t_cl_arg_list	*new;

	printf("Kernel Args : Initializing arguments\n");
	new = (t_cl_arg_list *)malloc(sizeof(t_cl_arg_list));
	new->context = context;
	new->queue = queue;
	new->length = 0;
	printf("Kernel Args : Ready\n\n");
	return (new);
}
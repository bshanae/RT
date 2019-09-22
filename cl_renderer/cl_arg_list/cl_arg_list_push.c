#include "cl_arg_list.h"

int					cl_arg_list_push
					(t_cl_arg_list *list, void *ptr,
					u_long size, cl_mem_flags type)
{
	int 			i;
	int 			error;

#ifndef RT_OPEN_CL_DISABLED
	if (list->length == RT_ARGS_CAPACITY)
		return (-1);
	i = list->length++;
	list->array[i].host = ptr;
	list->array[i].size = size;
	list->array[i].update_need = ptr != NULL;
	list->array[i].device = clCreateBuffer(list->context,
		type, size, NULL, &error);
	rt_assert_critical(error == 0, "Arg List : Buffer error");
	return (i);
#else
	return (-1);
#endif
}
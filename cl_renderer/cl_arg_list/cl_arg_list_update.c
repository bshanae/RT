#include "cl_arg_list.h"

void				cl_arg_list_update(t_cl_arg_list *list)
{
	int 			i;

	i = 0;
	while (i < list->length)
	{
		if (list->array[i].update_need)
			cl_args_list_write(list, i);
		list->array[i].update_need = 0;
		i++;
	}
}
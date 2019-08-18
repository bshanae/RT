#include "cl_builder.h"

void				cl_builder_set_args
					(t_cl_builder *builder, t_cl_arg_list *list)
{
	int 			i;

	i = 0;
	while (i < list->length)
	{
		builder->error = clSetKernelArg(builder->kernel,
			(u_long)i, sizeof(cl_mem), &list->array[i].device);
		ASSERT(builder->error == 0)
		i++;
	}
}

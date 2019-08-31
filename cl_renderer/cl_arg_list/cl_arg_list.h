#ifndef CL_ARG_LIST_H
# define CL_ARG_LIST_H

# include "rt_control.h"
# include "rt_parameters.h"

# include "rt_assert.h"
# include "cl_arg.h"

# include <stdio.h>

typedef struct 			s_cl_arg_list
{
	t_cl_arg			array[RT_CL_ARGS_CAPACITY];
	int 				length;
	cl_context 			context;
	cl_command_queue 	queue;
}						t_cl_arg_list;

t_cl_arg_list			*cl_arg_list_new
						(cl_context context, cl_command_queue queue);
void					cl_arg_list_delete(t_cl_arg_list **list);

int						cl_arg_list_push
						(t_cl_arg_list *list, void *ptr,
		 				u_long size, cl_mem_flags type);
void					cl_arg_list_update(t_cl_arg_list *list);

void					cl_args_list_read(t_cl_arg_list *list, int i);
void					cl_args_list_write(t_cl_arg_list *list, int i);

#endif

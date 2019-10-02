/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_arg_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:41:41 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CL_ARG_LIST_H
# define CL_ARG_LIST_H

# include "rt_control.h"
# include "rt_parameters.h"

# include "error_framework.h"
# include "cl_arg.h"

# include <stdio.h>

typedef struct			s_cl_arg_list
{
	t_cl_arg			array[RT_ARGS_CAPACITY];
	int					length;
	cl_context			context;
	cl_command_queue	queue;
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

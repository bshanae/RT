/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_arg_list_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:42:03 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_arg_list.h"

#ifndef RT_OPEN_CL_DISABLED

int					cl_arg_list_push(
					t_cl_arg_list *list,
					void *ptr,
					u_long size,
					cl_mem_flags type)
{
	int				i;
	int				error;

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
}

#else

int					cl_arg_list_push(
					t_cl_arg_list *list,
					void *ptr,
					u_long size,
					cl_mem_flags type)
{
	return (-1);
}

#endif

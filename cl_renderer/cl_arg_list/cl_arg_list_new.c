/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_arg_list_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:41:56 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_arg_list.h"

t_cl_arg_list			*cl_arg_list_new(
						cl_context context, cl_command_queue queue)
{
	t_cl_arg_list	*new;

	printf("Kernel Args : Initializing arguments\n");
	new = (t_cl_arg_list *)rt_malloc(sizeof(t_cl_arg_list));
	new->context = context;
	new->queue = queue;
	new->length = 0;
	printf("Kernel Args : Ready\n\n");
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_arg_list_delete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:41:48 by ashari            #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_arg_list.h"

#ifndef RT_OPEN_CL_DISABLED

void				cl_arg_list_delete(t_cl_arg_list **list)
{
	int				i;

	i = 0;
	while (i < (*list)->length)
		clReleaseMemObject((*list)->array[i++].device);
	free(*list);
	*list = NULL;
}

#else

void				cl_arg_list_delete(t_cl_arg_list **list)
{
	return ;
}

#endif

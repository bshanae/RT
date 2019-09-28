/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_arg_list_delete.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:41:48 by ashari            #+#    #+#             */
/*   Updated: 2019/09/28 13:41:49 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_arg_list.h"

void				cl_arg_list_delete(t_cl_arg_list **list)
{
	int				i;

	i = 0;
#ifndef RT_OPEN_CL_DISABLED
	while (i < (*list)->length)
		clReleaseMemObject((*list)->array[i++].device);
#endif
	free(*list);
	*list = NULL;
}

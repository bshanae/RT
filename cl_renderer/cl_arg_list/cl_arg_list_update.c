/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_arg_list_update.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:42:17 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_arg_list.h"

void				cl_arg_list_update(t_cl_arg_list *list)
{
	int				i;

	i = 0;
	while (i < list->length)
	{
		if (list->array[i].update_need)
			cl_args_list_write(list, i);
		list->array[i].update_need = 0;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl_set_arguments.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:11:50 by ashari            #+#    #+#             */
/*   Updated: 2019/07/01 12:05:47 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_cl.h"

void				open_cl_set_arguments(t_open_cl *me)
{
	int				error;

	error = clSetKernelArg(me->kernel,
		0, sizeof(cl_mem), &me->data_device.image);
	error += clSetKernelArg(me->kernel,
		1, sizeof(cl_mem), &me->data_device.scene);
	error_check(__LINE__, __FUNCTION__, error);
}

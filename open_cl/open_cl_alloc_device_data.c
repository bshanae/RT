/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl_alloc_device_data.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:11:20 by ashari            #+#    #+#             */
/*   Updated: 2019/06/30 19:11:21 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_cl.h"

void				open_cl_alloc_device(t_open_cl *me)
{
	int				error;

	me->data_device.image = clCreateBuffer(me->context,
		CL_MEM_WRITE_ONLY, me->data_size.image, NULL, &error);
	error_check(__LINE__, __FUNCTION__, error);
	me->data_device.scene = clCreateBuffer(me->context,
		CL_MEM_READ_ONLY, me->data_size.scene, NULL, &error);
	error_check(__LINE__, __FUNCTION__, error);
}

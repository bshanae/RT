/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl_create_device.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:11:27 by ashari            #+#    #+#             */
/*   Updated: 2019/06/30 19:11:28 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_cl.h"

void				open_cl_create_device(t_open_cl *me)
{
	cl_platform_id	platform;
	int				error;

	error = clGetPlatformIDs(1, &platform, NULL);
	error_check(__LINE__, __FUNCTION__, error);
	error =
		clGetDeviceIDs(platform, CL_DEVICE_TYPE_GPU, 1, &me->device_id, NULL);
	error_check(__LINE__, __FUNCTION__, error);
}

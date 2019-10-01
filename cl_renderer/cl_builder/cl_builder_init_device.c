/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_builder_init_device.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:49:42 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_builder.h"

void				cl_builder_init_device(t_cl_builder *builder)
{
	cl_platform_id	platform;

	printf("Kernel Builder : Initializing device\n");
	builder->error = clGetPlatformIDs(1, &platform, NULL);
	rt_assert_critical(builder->error == 0, "Builder : Platform error");
#ifdef RT_OPEN_CL_CPU
	builder->error = clGetDeviceIDs(platform,
		CL_DEVICE_TYPE_CPU, 1, &builder->device_id, NULL);
#elif defined RT_OPEN_CL_GPU
	builder->error = clGetDeviceIDs(platform,
		CL_DEVICE_TYPE_GPU, 1, &builder->device_id, NULL);
#endif
	rt_assert_critical(builder->error == 0, "Builder : Device error");
}

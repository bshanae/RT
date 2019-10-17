/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_builder_init_device.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:49:42 by ashari            #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_builder.h"

#ifdef RT_OPEN_CL_CPU

void				cl_builder_init_device(t_cl_builder *builder)
{
	cl_platform_id	platform;

	printf("Kernel Builder : Initializing device\n");
	builder->error = clGetPlatformIDs(1, &platform, NULL);
	rt_assert_critical(builder->error == 0, "Builder : Platform error");
	builder->error = clGetDeviceIDs(platform,
		CL_DEVICE_TYPE_CPU, 1, &builder->device_id, NULL);
	rt_assert_critical(builder->error == 0, "Builder : Device error");
}

#elif defined RT_OPEN_CL_GPU

void				cl_builder_init_device(t_cl_builder *builder)
{
	cl_platform_id	platform;

	printf("Kernel Builder : Initializing device\n");
	builder->error = clGetPlatformIDs(1, &platform, NULL);
	rt_assert_critical(builder->error == 0, "Builder : Platform error");
	builder->error = clGetDeviceIDs(platform,
		CL_DEVICE_TYPE_GPU, 1, &builder->device_id, NULL);
	rt_assert_critical(builder->error == 0, "Builder : Device error");
}

#endif

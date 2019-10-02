/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_builder_create_x.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:49:29 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_builder.h"

void				cl_builder_create_context(t_cl_builder *builder)
{
	printf("Kernel Builder : Initializing context\n");
	builder->context = clCreateContext(NULL, 1,
		&builder->device_id, 0, 0, &builder->error);
	rt_assert_critical(builder->error == 0, "Builder : Context error");
}

void				cl_builder_create_kernel(t_cl_builder *builder)
{
	printf("Kernel Builder : Creating kernel\n");
	builder->kernel = clCreateKernel(builder->program->program,
		RT_CL_MAIN_FUNCTION, &builder->error);
	rt_assert_critical(builder->error == 0, "Builder : Kernel error");
}

void				cl_builder_create_queue(t_cl_builder *builder)
{
	printf("Kernel Builder : Creating kernels' queue\n");
	builder->queue = clCreateCommandQueue(builder->context,
	builder->device_id, 0, &builder->error);
	rt_assert_critical(builder->error == 0, "Builder : Queue error");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_builder_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:49:35 by ashari            #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_builder.h"

#ifndef RT_OPEN_CL_DISABLED

void				cl_builder_delete(t_cl_builder **builder)
{
	clReleaseDevice((*builder)->device_id);
	clReleaseContext((*builder)->context);
	clReleaseKernel((*builder)->kernel);
	clReleaseCommandQueue((*builder)->queue);
	cl_program_delete(&(*builder)->program);
	free(*builder);
	*builder = NULL;
}

#else

void				cl_builder_delete(t_cl_builder **builder)
{
	free(*builder);
	*builder = NULL;
}

#endif

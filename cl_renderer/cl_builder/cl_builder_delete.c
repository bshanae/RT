/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_builder_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:49:35 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_builder.h"

void				cl_builder_delete(t_cl_builder **builder)
{
#ifndef RT_OPEN_CL_DISABLED
	clReleaseDevice((*builder)->device_id);
	clReleaseContext((*builder)->context);
	clReleaseKernel((*builder)->kernel);
	clReleaseCommandQueue((*builder)->queue);
	cl_program_delete(&(*builder)->program);
#endif
	free(*builder);
	*builder = NULL;
}

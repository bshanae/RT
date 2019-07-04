/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl_create_kernel.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:11:32 by ashari            #+#    #+#             */
/*   Updated: 2019/07/01 12:05:47 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_cl.h"

void				open_cl_create_kernel(t_open_cl *me)
{
	int				error;

	me->kernel = clCreateKernel(me->program, CL_FUNCTION, &error);
	error_check(__LINE__, __FUNCTION__, error);
}

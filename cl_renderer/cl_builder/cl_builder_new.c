/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_builder_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:49:55 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_builder.h"

t_cl_builder		*cl_builder_new(void)
{
	t_cl_builder	*new;

	new = (t_cl_builder *)rt_malloc(sizeof(t_cl_builder));
	new->program = cl_program_new(RT_SOURCE_CL_FOLDER);
	cl_builder_init_device(new);
	cl_builder_create_context(new);
	cl_builder_create_program_a(new);
	cl_builder_create_program_b(new);
	cl_builder_create_kernel(new);
	cl_builder_create_queue(new);
	printf("Kernel Builder : Ready\n\n");
	return (new);
}

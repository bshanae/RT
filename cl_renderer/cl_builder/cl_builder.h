/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_builder.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:49:22 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CL_BUILDER_H
# define CL_BUILDER_H

# include "rt_control.h"
# include "rt_cl_include.h"
# include "rt_sources_cl.h"

# include "error_framework.h"
# include "cl_program.h"
# include "cl_arg_list.h"

# include <stdio.h>

typedef struct			s_cl_builder
{
	cl_device_id		device_id;
	cl_context			context;
	cl_kernel			kernel;
	cl_command_queue	queue;
	int					error;
	t_cl_program		*program;
}						t_cl_builder;

t_cl_builder			*cl_builder_new(void);
void					cl_builder_delete(t_cl_builder **builder);

void					cl_builder_init_device(t_cl_builder *builder);
void					cl_builder_create_context(t_cl_builder *builder);

void					cl_builder_create_program_a(t_cl_builder *builder);
void					cl_builder_create_program_b(t_cl_builder *builder);
void					cl_builder_create_kernel(t_cl_builder *builder);
void					cl_builder_create_queue(t_cl_builder *builder);

void					cl_builder_set_args
						(t_cl_builder *builder, t_cl_arg_list *list);

void					cl_builder_log(t_cl_builder *builder);

#endif

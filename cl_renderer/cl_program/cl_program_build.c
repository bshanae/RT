/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_program_build.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:58:56 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_program.h"

int					cl_program_build(
					t_cl_program *program,
					cl_context context, CHAR_REF flags)
{
	program->buffer[program->length] = '\0';
	program->program = clCreateProgramWithSource(context, 1,
		(const char **)&program->buffer, &program->length, &program->error);
	rt_assert_critical(program->error == 0, "Builder : Program error");
	program->error =
		clBuildProgram(program->program, 0, NULL, flags, NULL, NULL);
	return (program->error != 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:11:46 by ashari            #+#    #+#             */
/*   Updated: 2019/07/01 12:05:47 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_cl.h"

void				error_raise(int line, const char *function_name, int error)
{
	ft_printf("Error no. %d on line %d in %s\n", error, line, function_name);
	exit(17);
}

void				error_check(int line, const char *function_name, int error)
{
	if (error < 0)
		error_raise(line, function_name, error);
}

void				error_log(t_open_cl *me, cl_program *program, int error)
{
	char			*log;
	u_long			log_length;

	clGetProgramBuildInfo(*program, me->device_id,
		CL_PROGRAM_BUILD_LOG, 0, NULL, &log_length);
	log = ft_strnew(log_length);
	clGetProgramBuildInfo(*program, me->device_id,
		CL_PROGRAM_BUILD_LOG, log_length + 1, log, NULL);
	ft_printf("LOG (%d): \n%s\n", error, log);
	free(log);
	exit(1);
}

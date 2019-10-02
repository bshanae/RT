/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_builder_log.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:49:49 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_builder.h"

void				cl_builder_log(t_cl_builder *builder)
{
	char			*log;
	u_long			log_length;
	FILE			*file;

	clGetProgramBuildInfo(builder->program->program, builder->device_id,
		CL_PROGRAM_BUILD_LOG, 0, NULL, &log_length);
	log = ft_strnew(log_length);
	clGetProgramBuildInfo(builder->program->program, builder->device_id,
		CL_PROGRAM_BUILD_LOG, log_length + 1, log, NULL);
	printf("cl compilation log (%d): \n%s\n", builder->program->error, log);
	free(log);
	file = fopen("./cl_renderer/cl_build.c", "w");
	fprintf(file, "%s\n", builder->program->buffer);
	fclose(file);
	exit(1);
}

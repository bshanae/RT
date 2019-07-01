/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl_create_program.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:11:36 by ashari            #+#    #+#             */
/*   Updated: 2019/07/01 12:05:47 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_cl.h"

static void			read_program
	(const char *file_name, char **target, u_long *length)
{
	int				fd;
	char			*buffer;
	u_long			buffer_capacity;
	u_long			buffer_unit;
	u_long			buffer_length;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		error_raise(__LINE__, __FUNCTION__, 0);
	buffer = (char *)malloc(OCL_BUFF_INIT);
	buffer_capacity = OCL_BUFF_INIT;
	buffer_length = 0;
	while ((buffer_unit = read(fd, buffer + buffer_length, 64)) > 0)
	{
		buffer_length += buffer_unit;
		if (buffer_length + 64 > buffer_capacity)
		{
			ft_realloc((void **)&buffer,
			buffer_capacity, buffer_capacity * OCL_BUFF_MULT);
			buffer_capacity *= OCL_BUFF_MULT;
		}
	}
	*target = buffer;
	*length = buffer_length;
}

void				open_cl_create_program(t_open_cl *me)
{
	int				error;
	char			*buffer;
	u_long			length;

	read_program(CL_SOURCE, &buffer, &length);
	me->program = clCreateProgramWithSource(me->context, 1,
		(const char **)&buffer, &length, &error);
	free(buffer);
	error_check(__LINE__, __FUNCTION__, error);
	error = clBuildProgram(me->program, 0, NULL, CL_OPTIONS, NULL, NULL);
	if (error < 0)
		error_log(me, &me->program, error);
}

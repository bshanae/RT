/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_program_concat.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:59:02 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_program.h"

static void			cl_program_realloc(t_cl_program *program)
{
	ft_realloc((void **)&program->buffer,
	program->capacity, program->capacity * 2);
	program->capacity *= 2;
}

void				cl_program_concat(t_cl_program *program, CHAR_REF file)
{
	int				fd;
	char			file_full[64];
	int				read_length;
	int				nl_counter;

	ft_strcpy(file_full, program->path);
	ft_strcat(file_full, file);
	fd = open(file_full, O_RDONLY);
	rt_assert_critical(fd != -1,
		"Builder : Invalid file (path = %s)", file_full);
	while (1)
	{
		if ((program->length + 64.) / program->capacity > 0.5)
			cl_program_realloc(program);
		if ((read_length = read(fd, program->buffer + program->length, 64)) < 1)
			break ;
		program->length += read_length;
	}
	nl_counter = 0;
	nl_counter += program->buffer[program->length - 2] != '\n';
	nl_counter += program->buffer[program->length - 1] != '\n';
	while (nl_counter-- > 0)
		program->buffer[program->length++] = '\n';
	close(fd);
}

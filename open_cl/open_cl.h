/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:11:58 by ashari            #+#    #+#             */
/*   Updated: 2019/07/01 12:05:47 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPEN_CL_H
# define OPEN_CL_H

# include <OpenCL/CL.h>

# include "libft_ft_printf.h"

# include "camera.h"
# include "scene.h"
# include "shape_list.h"
# include "parameters.h"

# define CL_SOURCE		"../open_cl/program.cl"
# define CL_FUNCTION	"render"
# define CL_OPTIONS		"-I ../"

# define OCL_BUFF_INIT 1000
# define OCL_BUFF_MULT 5

typedef struct			s_host_data
{
	int					*image;
}						t_host_data;

typedef struct			s_device_data
{
	cl_mem				image;
	cl_mem				scene;
}						t_device_data;

typedef struct			s_data_size
{
	u_long				image;
	u_long				scene;
}						t_data_size;

typedef struct			s_open_cl
{
	cl_device_id		device_id;
	cl_context			context;
	cl_program			program;
	cl_kernel			kernel;
	cl_command_queue	queue;
	u_long				total_size;
	t_host_data			data_host;
	t_device_data		data_device;
	t_data_size			data_size;
}						t_open_cl;

t_open_cl				*open_cl_new(int *image);

void					open_cl_delete(t_open_cl **me);

void					error_raise
						(int line,
						const char *function_name,
						int error);

void					error_check
						(int line,
						const char *function_name,
						int error);

void					error_log
						(t_open_cl *me,
						cl_program *program,
						int error);

void					open_cl_create_device(t_open_cl *me);

void					open_cl_create_context(t_open_cl *me);

void					open_cl_create_program(t_open_cl *me);

void					open_cl_create_queue(t_open_cl *me);

void					open_cl_create_kernel(t_open_cl *me);

void					open_cl_alloc_device(t_open_cl *me);

void					open_cl_set_arguments(t_open_cl *me);

void					open_cl_run(t_open_cl *me, t_scene *scene);

#endif

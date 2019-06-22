#ifndef OPEN_CL_H
# define OPEN_CL_H

# define CL_SILENCE_DEPRECATION

# include <OpenCL/CL.h>

# include "libft_ft_printf.h"

# include "camera.h"
# include "scene.h"
# include "shape_list.h"

# define CL_SOURCE		"../rt/rt_parallel.cl"
# define CL_FUNCTION	"cl_trace_ray"
# define CL_FLAGS		"-I ../float_macro"

# define OCL_BUFF_INIT 1000
# define OCL_BUFF_MULT 5

# define CHECK_ERROR	if (error < 0) raise_error(__LINE__, __FUNCTION__, error);

typedef struct 			s_host_data
{
	int 				*image;
	t_camera_cl			camera;
	t_scene_cl			scene;
	void				*shape_data;
	t_shape_cl			*shapes;
	t_light				*lights;
	int 				reflection_depth;
	int 				refraction_depth;
	int 				win_width;
	int 				win_height;
}						t_host_data;

typedef struct 			s_device_data
{
	cl_mem 				camera;
	cl_mem 				shape_data;
	cl_mem 				scene;
	cl_mem				shapes;
	cl_mem				lights;
	cl_mem				reflection_depth;
	cl_mem				refraction_depth;
	cl_mem 				win_width;
	cl_mem 				win_height;
	cl_mem 				image;
	cl_mem 				kostyl;
}						t_device_data;

typedef struct 			s_data_size
{
	u_long 				image;
	u_long 				camera;
	u_long 				shape_data;
	u_long 				scene;
	u_long 				shapes;
	u_long 				lights;
	u_long 				reflection_depth;
	u_long 				refraction_depth;
	u_long 				win_width;
	u_long 				win_height;
}						t_data_size;

typedef struct 			s_open_cl
{
	cl_device_id		device_id;
	cl_context			context;
	cl_program			program;
	cl_kernel			kernel;
	cl_command_queue	queue;
	u_long 				total_size;
	t_data_size			size;
	t_host_data			host;
	t_device_data		device;
}						t_open_cl;

t_open_cl				*open_cl_new(int *image, int width, int height);

void					open_cl_delete(t_open_cl **me);

void					open_cl_alloc_device(t_open_cl *me, const t_scene *scene);

void					open_cl_set_args(t_open_cl *me);

void 					open_cl_run(t_open_cl *me);

#endif
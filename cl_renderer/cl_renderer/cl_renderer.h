#ifndef CL_RENDERER_H
# define CL_RENDERER_H

# include "rt_control.h"
# include "rt_float.h"

# include "gui_image.h"
# include "cl_arg_list.h"
# include "cl_builder.h"
# include "scene.h"
# include "camera.h"
# include "ray.h"

# include <stdlib.h>
# include <time.h>

typedef struct 				s_cl_renderer_settings
{
	int						sample_count;
	int						sample_limit;
	int 					sample_depth;
	int						russian_depth;
	int						srgb;
	int						light_pb;
	int 					light_explicit;
}							t_cl_renderer_settings;

typedef struct 				s_cl_renderer_flag_list
{
	int 					summary;
	int						update_camera;
	int 					update_scene;
	int						update_settings;
	int						reset_samples;
}							t_cl_renderer_flag_list;

typedef enum				e_cl_renderer_flag
{
	cl_flag_update_camera,
	cl_flag_update_scene,
	cl_flag_update_settings,
	cl_flag_reset_samples
}							t_cl_renderer_flag;

typedef	struct 				s_cl_renderer_data
{
	t_camera				*camera;
	t_scene					*scene;
	t_color					*image;
	t_cl_renderer_settings	settings;
	u_long					*rng_state;
}							t_cl_renderer_data;

typedef struct 				s_cl_renderer
{
	t_gui_image				*image;
	u_long 					pixel_number;
	t_cl_builder			*builder;
	t_cl_arg_list			*args;
	t_cl_renderer_flag_list	flags;
	t_cl_renderer_data		data;
}							t_cl_renderer;

typedef enum				e_cl_renderer_arg
{
	cl_arg_camera,
	cl_arg_scene,
	cl_arg_image,
	cl_arg_settings,
	cl_arg_samples,
	cl_arg_rng_state
}							t_cl_renderer_arg;

t_cl_renderer				*cl_renderer_new(t_gui_image *image);
void						cl_renderer_delete(t_cl_renderer **renderer);

void						cl_renderer_flag_set(t_cl_renderer *renderer,
												 t_cl_renderer_flag flag);
void						cl_renderer_flag_perform(t_cl_renderer *renderer);

void 						cl_renderer_camera_move
							(t_cl_renderer *renderer, t_camera_movement movement);
void 						cl_renderer_camera_rotate(
							t_cl_renderer *renderer,
		 					t_f4_rotation_axis axis,
		 					t_f4_rotation_direction direction);

void						cl_renderer_render(t_cl_renderer *renderer);

#endif

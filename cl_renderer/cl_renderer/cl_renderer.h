/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_renderer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:01:56 by ashari            #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CL_RENDERER_H
# define CL_RENDERER_H

# include "rt_cl_include.h"
# include "rt_control.h"
# include "rt_float.h"

# include "gui_image.h"
# include "scene.h"
# include "camera.h"
# include "ray.h"
# include "cl_arg_list.h"
# include "cl_builder.h"
# include "cl_renderer_flag_x.h"
# include "../rt_settings/rt_settings.h"
# include "json_parse.h"

# include <stdlib.h>
# include <time.h>

typedef	struct				s_cl_renderer_data
{
	t_camera				*camera_unmodified;
	t_camera				*camera;
	t_scene					*scene;
	t_color					*image;
	t_rt_settings			settings;
	u_long					*rng_state;
}							t_cl_renderer_data;

typedef struct				s_cl_renderer
{
	t_gui_image				*image;
	u_long					pixel_number;
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
	cl_arg_samples,
	cl_arg_settings,
	cl_arg_rng_state
}							t_cl_renderer_arg;

t_cl_renderer				*cl_renderer_new(t_gui_image *image);
void						cl_renderer_delete(t_cl_renderer **renderer);

void						cl_renderer_flag_set(t_cl_renderer *renderer,
							t_cl_renderer_flag flag);
void						cl_renderer_flag_perform(t_cl_renderer *renderer);

void						cl_renderer_change_tracing_mod
							(t_cl_renderer *renderer, t_rt_tracing_mod mod);
void						cl_renderer_change_light_mod
							(t_cl_renderer *renderer, t_rt_light_mod mod);
void						cl_renderer_change_background
							(t_cl_renderer *renderer, t_rt_background back);

int							cl_renderer_camera_move
							(t_cl_renderer *renderer, t_rt_movement movement);
void						cl_renderer_camera_rotate(
							t_cl_renderer *renderer,
							t_f4_rotation_axis axis,
							t_f4_rotation_direction direction);
void						cl_renderer_camera_reset(t_cl_renderer *renderer);
void						cl_renderer_camera_save(t_cl_renderer *renderer);
void						cl_renderer_camera_request_focus
							(t_cl_renderer *renderer, int x, int y);
void						cl_renderer_camera_request_select
							(t_cl_renderer *renderer, int x, int y);

void						cl_renderer_object_move
							(t_cl_renderer *renderer, t_rt_movement movement);
void						cl_renderer_object_select
							(t_cl_renderer *renderer, int id);

void						cl_renderer_load
							(t_cl_renderer *renderer, const char *path);

void						cl_renderer_queue_pre(t_cl_renderer *renderer);
void						cl_renderer_queue_in(t_cl_renderer *renderer);
void						cl_renderer_queue_post(t_cl_renderer *renderer);

void						cl_renderer_render(t_cl_renderer *renderer);

#endif

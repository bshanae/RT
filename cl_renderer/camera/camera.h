/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:33:12 by ashari            #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "rt_parameters.h"
# include "rt_float.h"

# include "libft_standart.h"
# include "error_framework.h"
# include "f4.h"
# include "ray.h"

# include <stdlib.h>
# include <math.h>

typedef struct		s_camera
{
	RT_F4_API		position;
	RT_F4_API		rotation;
	RT_F4_API		axis_x;
	RT_F4_API		axis_y;
	RT_F4_API		axis_z;
	RT_F4_API		forward;
	RT_F4_API		forward_backup;
	int				width;
	int				height;
	int				filter_antialiasing;
	t_rt_filter_mod	filter_mod;
	int				focus;
	RT_F			aperture_size;
	RT_F			focal_length;
	int				focus_request;
	int				select_request;
	int				select_request_object;
	RT_F2_API		request_value;
}					t_camera;

void				camera_default(t_camera *camera);
t_camera			*camera_new(INT_REF width, INT_REF height);
void				camera_delete(t_camera **camera);

RT_F4_API			camera_get_step(t_camera *camera, t_rt_movement movement);
RT_F4_API			camera_move
					(t_camera *camera,
					t_rt_movement direction,
					RT_F length);
void				camera_rotate
					(t_camera *camera,
					t_f4_rotation_axis axis,
					t_f4_rotation_direction direction,
					RT_F theta);
void				camera_apply(t_camera *camera);

void				camera_request_focus(t_camera *camera, int x, int y);
void				camera_request_select(t_camera *camera, int x, int y);

#endif

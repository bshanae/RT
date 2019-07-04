/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:10:30 by ashari            #+#    #+#             */
/*   Updated: 2019/07/02 11:17:32 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector3.h"
# include "ray.h"

typedef struct			s_camera
{
	t_vector3			position;
	float				direction_length;
	t_vector3			direction;
	t_vector3			axis_x;
	t_vector3			axis_y;
	t_vector3			axis_z;
	t_vector3			vp_axis_x;
	t_vector3			vp_axis_y;
	t_vector3			angles;
}						t_camera;

t_camera				camera_build(float direction_length);

void					camera_recalculate(t_camera *me);

#endif

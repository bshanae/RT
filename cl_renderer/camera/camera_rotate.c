/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:34:14 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

void				camera_rotate(
					t_camera *camera,
					t_f4_rotation_axis axis,
					t_f4_rotation_direction direction,
					RT_F theta)
{
	if (direction == rt_rotation_negative)
		theta *= -1;
	if (axis == rt_rotation_x)
		camera->rotation.x += theta;
	else if (axis == rt_rotation_y)
		camera->rotation.y += theta;
	camera_apply(camera);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:33:48 by ashari            #+#    #+#             */
/*   Updated: 2019/09/28 13:33:50 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

RT_F4_API			camera_move(
					t_camera *camera,
					t_rt_movement movement,
					RT_F length)
{
	RT_F4_API		step;

	step = camera_get_step(camera, movement);
	step = f4_mul(step, length);
	return (f4_add(camera->position, step));
}

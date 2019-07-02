/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:10:21 by ashari            #+#    #+#             */
/*   Updated: 2019/07/02 11:17:32 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"

t_camera			camera_build(float direction_length)
{
	t_camera		new;

	new.position = (t_vector3){0., 0., 0.};
	new.direction_length = direction_length;
	new.direction = (t_vector3){0., 0., -direction_length};
	new.axis_x = (t_vector3){1., 0., 0.};
	new.axis_y = (t_vector3){0., 1., 0.};
	new.axis_z = (t_vector3){0., 0., 1.};
	new.vp_axis_x = (t_vector3){1., 0., 0.};
	new.vp_axis_y = (t_vector3){0., 1., 0.};
	new.angles = (t_vector3){0., 0., 0.};
	return (new);
}

void				camera_recalculate(t_camera *me)
{
	int				index;
	t_vector3		*iter;

	me->direction = (t_vector3){0., 0., -1 * me->direction_length};
	me->axis_x = (t_vector3){1., 0., 0.};
	me->axis_y = (t_vector3){0., 1., 0.};
	me->axis_z = (t_vector3){0., 0., 1.};
	me->vp_axis_x = (t_vector3){1., 0., 0.};
	me->vp_axis_y = (t_vector3){0., 1., 0.};
	index = 0;
	iter = &me->direction;
	while (index < 6)
	{
		vector3_rotate_x(iter + index, me->angles.x);
		vector3_rotate_y(iter + index, me->angles.y);
		index++;
	}
}

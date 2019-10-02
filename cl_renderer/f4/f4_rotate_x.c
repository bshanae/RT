/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f4_rotate_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:29:05 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f4.h"

static void			f4_rotate_x(RT_F4_API *v, RT_F theta)
{
	RT_F4_API		copy;

	copy = *v;
	v->y = copy.y * RT_COS_API(theta) + copy.z * RT_SIN_API(theta);
	v->z = -1 * copy.y * RT_SIN_API(theta) + copy.z * RT_COS_API(theta);
}

static void			f4_rotate_y(RT_F4_API *v, RT_F theta)
{
	RT_F4_API		copy;

	copy = *v;
	v->x = copy.x * RT_COS_API(theta) + copy.z * RT_SIN_API(theta);
	v->z = -1 * copy.x * RT_SIN_API(theta) + copy.z * RT_COS_API(theta);
}

static void			f4_rotate_z(RT_F4_API *v, RT_F theta)
{
	RT_F4_API		copy;

	copy = *v;
	v->x = copy.x * RT_COS_API(theta) - copy.y * RT_SIN_API(theta);
	v->y = copy.x * RT_SIN_API(theta) + copy.y * RT_COS_API(theta);
}

RT_F4_API			f4_rotate(
					RT_F4_API v,
					t_f4_rotation_axis axis,
					t_f4_rotation_direction direction,
					RT_F theta)
{
	if (direction == rt_rotation_negative)
		theta *= -1;
	if (axis == rt_rotation_x)
		f4_rotate_x(&v, theta);
	else if (axis == rt_rotation_y)
		f4_rotate_y(&v, theta);
	else if (axis == rt_rotation_z)
		f4_rotate_z(&v, theta);
	return (v);
}

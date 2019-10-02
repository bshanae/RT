/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f4.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:28:20 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef F4_H
# define F4_H

# include "rt_cl_include.h"
# include "rt_float.h"

# include <math.h>

typedef enum		e_f4_rotation_axis
{
	rt_rotation_x,
	rt_rotation_y,
	rt_rotation_z
}					t_f4_rotation_axis;

typedef enum		e_f4_rotation_direction
{
	rt_rotation_positive,
	rt_rotation_negative
}					t_f4_rotation_direction;

RT_F4_API			f4_add(RT_F4_API a, RT_F4_API b);
RT_F4_API			f4_sub(RT_F4_API a, RT_F4_API b);
RT_F4_API			f4_mul(RT_F4_API v, RT_F f);

RT_F4_API			f4_rotate(
					RT_F4_API v,
					t_f4_rotation_axis axis,
					t_f4_rotation_direction direction,
					RT_F theta);

RT_F				f4_length(RT_F4_API f4);
RT_F4_API			f4_normalize(RT_F4_API source);

RT_F				f4_dot(RT_F4_API a, RT_F4_API b);

RT_F4_API			f4_cross(RT_F4_API a, RT_F4_API b);

#endif

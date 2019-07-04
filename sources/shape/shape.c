/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:13:23 by ashari            #+#    #+#             */
/*   Updated: 2019/07/02 11:17:32 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape_list.h"

void				shape_move(t_shape *shape, t_vector3 step)
{
	if (shape->id == SHAPE_ID_SPHERE)
		sphere_move(shape, step);
	else if (shape->id == SHAPE_ID_PLANE)
		plane_move(shape, step);
	else if (shape->id == SHAPE_ID_CYLINDER)
		cylinder_move(shape, step);
	else if (shape->id == SHAPE_ID_CONE)
		cone_move(shape, step);
	else if (shape->id == SHAPE_ID_AABB)
		aabb_move(shape, step);
}

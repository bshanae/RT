/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:13:20 by ashari            #+#    #+#             */
/*   Updated: 2019/07/01 12:05:47 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape_list.h"

void				sphere_move(t_shape *shape, t_vector3 move)
{
	t_sphere_data	*data;

	data = (t_sphere_data *)shape->data;
	vector3_add_eq(&data->center, &move);
}

t_shape				shape_sphere
	(t_vector3 center, float radius, t_material material)
{
	t_shape			shape;
	t_sphere_data	*data;

	shape.id = SHAPE_ID_SPHERE;
	data = (t_sphere_data *)shape.data;
	data->center = center;
	data->radius = radius;
	shape.material = material;
	shape.highlight = 0;
	return (shape);
}

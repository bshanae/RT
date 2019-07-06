/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:13:20 by ashari            #+#    #+#             */
/*   Updated: 2019/07/06 15:05:40 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shape_list.h"

int					sphere_intersect(t_shape *shape, t_intersection *intersection)
{
	t_sphere_data	*data;
	float 	k[3];
	float 	t;
	float 	discriminant;
	t_vector3		temp;

	data = (t_sphere_data *)shape->data;
	k[0] = vector3_dot(&intersection->ray.direction, &intersection->ray.direction);
	temp = vector3_sub(&intersection->ray.origin, &data->center);
	k[1] = 2 * vector3_dot(&temp, &intersection->ray.direction);
	k[2] = vector3_dot(&temp, &temp) - data->radius * data->radius;
	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	if (discriminant < 0.)
		return (0);
	t = (-k[1] - sqrtf(discriminant)) / (2 * k[0]);
	if (t <= RAY_T_MIN || t >= intersection->ray.t)
		return (0);
	intersection->ray.t = t;
	temp = ray_intersect(&intersection->ray);
	intersection->normal = vector3_sub(&temp, &data->center);
	vector3_normalize(&intersection->normal);
	intersection->color = shape->material.color;
	intersection->material = shape->material;
	return (1);
}

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
	return (shape);
}

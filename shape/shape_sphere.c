#include "shape_list.h"

int					sphere_intersect
	(t_shape *shape, t_intersection *intersection)
{
	t_sphere_data	*data;
	FLOAT_MACRO 	k[3];
	FLOAT_MACRO 	t;
	FLOAT_MACRO 	discriminant;
	t_vector3		temp;

	data = (t_sphere_data *)shape->data;
	k[0] = vector3_dot(&intersection->ray.direction, &intersection->ray.direction);
	temp = vector3_sub(&intersection->ray.origin, &data->center);
	k[1] = 2 * vector3_dot(&temp, &intersection->ray.direction);
	k[2] = vector3_dot(&temp, &temp) - data->radius * data->radius;
	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	if (discriminant < 0.)
		return (0);
	t = (-k[1] - SQRT_MACRO(discriminant)) / (2 * k[0]);
	if (t <= RAY_T_MIN || t >= intersection->ray.t)
		return (0);
	intersection->ray.t = t;
	temp = ray_intersect(&intersection->ray);
	intersection->normal = vector3_sub(&temp, &data->center);
	vector3_normalize(&intersection->normal);
	intersection->color = shape->material->color;
	intersection->material = shape->material;
	intersection->highlight = &shape->highlight;
	return (1);
}

static void			sphere_move(t_shape *shape, t_vector3 move)
{
	t_sphere_data	*data;

	data = (t_sphere_data *)shape->data;
	vector3_add_eq(&data->center, &move);
}

t_shape				*shape_sphere
	(t_vector3 center, FLOAT_MACRO radius, const t_material *material)
{
	t_shape			*shape;
	t_sphere_data	*data;

	if (!(shape = (t_shape *)malloc(sizeof(t_shape))))
		exit(21);
	if (!(data = (t_sphere_data *)malloc(sizeof(t_sphere_data))))
		exit(21);
	data->center = center;
	data->radius = radius;
	shape->material = material;
	shape->data = (void *)data;
	shape->data_size = sizeof(t_sphere_data);
	shape->intersect = sphere_intersect;
	shape->move = sphere_move;
	shape->highlight = 0;
	return (shape);
}
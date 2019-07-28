#include "shape_list.h"

int 				disk_intersect(t_shape *shape, t_intersection *intersection)
{
	t_disk_data		*data;
	double 			t;

	data = (t_disk_data *)shape->data;
	if (!vector3_dot(&intersection->ray.direction, &data->normal))
		return (0);
	t = vector3_s_dot(data->normal, vector3_sub(&data->position, &intersection->ray.origin)) / vector3_dot(&intersection->ray.direction, &data->normal);
	if (vector3_s_length(vector3_s_sub(vector3_s_add(intersection->ray.origin, vector3_mul(&intersection->ray.direction, t)), data->position)) > data->radius)
		return (0);
	if (t <= RAY_T_MIN || t >= intersection->ray.t)
		return (0);
	intersection->ray.t = t;
	intersection->normal = data->normal;
	intersection->color = shape->material->color;
	intersection->material = shape->material;
	intersection->highlight = &shape->highlight;
	return (1);
}

static void			disk_move(t_shape *shape, t_vector3 move)
{
	t_disk_data	*data;

	data = (t_disk_data *)shape->data;
	vector3_add_eq(&data->position, &move);
}

t_shape				*shape_disk
	(t_vector3 position, t_vector3 normal, double radius, const t_material *material)
{
	t_shape			*shape;
	t_disk_data		*data;

	if (!(shape = (t_shape *)malloc(sizeof(t_shape))))
		exit(21);
	if (!(data = (t_disk_data *)malloc(sizeof(t_disk_data))))
		exit(21);
	data->position = position;
	data->normal = vector3_normalized(&normal);
	data->radius = radius;
	shape->material = material;
	shape->data = (void *)data;
	shape->data_size = sizeof(t_disk_data);
	shape->intersect = disk_intersect;
	shape->move = disk_move;
	shape->highlight = 0;
	return (shape);
}

#include "shape_list.h"

int 			plane_intersect
	(t_shape *shape, t_intersection *intersection)
{
	t_plane_data	*data;
	t_vector3		temp[2];
	FLOAT_MACRO 			value[3];

	data = (t_plane_data *)shape->data;
	if (!(value[0] = vector3_dot(&intersection->ray.direction, &data->normal)))
		return (0);
	temp[0] = vector3_sub(&data->position, &intersection->ray.origin);
	value[1] = vector3_dot(temp, &data->normal) / value[0];
	if (value[1] <= RAY_T_MIN || value[1] >= intersection->ray.t)
		return (0);
	intersection->ray.t = value[1];
	intersection->normal = data->normal;
	intersection->color = shape->material->color;
	intersection->material = shape->material;
	intersection->highlight = &shape->highlight;
	return (1);
}

static void			plane_move(t_shape *shape, t_vector3 move)
{
	t_plane_data	*data;

	data = (t_plane_data *)shape->data;
	vector3_add_eq(&data->position, &move);
}

t_shape				*shape_plane
	(t_vector3 position, t_vector3 normal, const t_material *material)
{
	t_shape			*shape;
	t_plane_data	*data;

	if (!(shape = (t_shape *)malloc(sizeof(t_shape))))
		exit(21);
	if (!(data = (t_plane_data *)malloc(sizeof(t_plane_data))))
		exit(21);
	data->position = position;
	data->normal = vector3_normalized(&normal);
	shape->material = material;
	shape->data = (void *)data;
	shape->data_size = sizeof(t_plane_data);
	shape->intersect = plane_intersect;
	shape->move = plane_move;
	shape->highlight = 0;
	return (shape);
}
#include "shape_list.h"

int						shape_intersect_plane(t_shape *shape, t_intersection *intersection)
{
	t_shape_data_plane	*data;
	t_vector3			temp[2];
	float 				value[2];

	data = (t_shape_data_plane *)shape->data;
	if (fabsf(value[0] = vector3_dot_ref(&intersection->ray.direction, &data->normal)) < INTERSECTION_MIN)
		return (0);
	temp[0] = vector3_sub_ref(&data->position, &intersection->ray.origin);
	value[1] = vector3_dot_ref(temp, &data->normal) / value[0];
	if (value[1] <= INTERSECTION_MIN || value[1] >= intersection->ray.t)
		return (0);
	intersection->ray.t = value[1];
	intersection->normal = data->normal;
	intersection->material = shape->material;
	intersection->hit = ray_calculate(&intersection->ray);
	return (1);
}

t_shape					shape_plane(t_vector3 position, t_vector3 normal, t_material material)
{
	t_shape				shape;
	t_shape_data_plane	*data;

	data = (t_shape_data_plane *)shape.data;
	data->position = position;
	data->normal = normal;
	shape.id = SHAPE_ID_PLANE;
	shape.material = material;
	return (shape);
}

#include "object_interaction.h"

void				object_plane_build(t_object *space, va_list *args)
{
	t_object_plane	*data;

	data = (t_object_plane *)space->data;
	data->position = va_arg(*args, t_vector3);
	data->normal = va_arg(*args, t_vector3);
	space->type = object_plane;
}

int						object_plane_intersect(t_object *object, t_intersection *intersection)
{
	t_object_plane		*data;
	t_vector3			temp[2];
	double 				value[2];

	data = (t_object_plane *)object->data;
	if (fabs(value[0] = vector3_dot_ref(&intersection->ray.direction, &data->normal)) < INTERSECTION_MIN)
		return (0);
	temp[0] = vector3_sub_ref(&data->position, &intersection->ray.origin);
	value[1] = vector3_dot_ref(temp, &data->normal) / value[0];
	if (value[1] <= INTERSECTION_MIN || value[1] >= intersection->ray.t)
		return (0);
	intersection->ray.t = value[1];
//	intersection->normal = data->normal;
//	intersection->material = object->material;
//	intersection->hit = ray_calculate(&intersection->ray);
	return (1);
}

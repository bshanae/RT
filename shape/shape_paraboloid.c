#include "shape_list.h"

int							paraboloid_intersect(t_shape *shape, t_intersection *intersection)
{
	t_shape_data_paraboloid	*data;
	t_vector3				tmp_vector;
	double 					t;
	double 					temp_value;
	double 					discriminant;
	double 					k[3];
	double 					x_dot_axis;
	double 					dir_dot_axis;

	data = (t_shape_data_paraboloid *)shape->data;
	tmp_vector = vector3_sub(&intersection->ray.origin, &data->extremum_point);
	x_dot_axis = vector3_dot(&tmp_vector, &data->normal);
	dir_dot_axis = vector3_dot(&intersection->ray.direction, &data->normal);
	k[0] = vector3_dot(&intersection->ray.direction, &intersection->ray.direction) - dir_dot_axis * dir_dot_axis;
	k[1] = 2 * (vector3_dot(&intersection->ray.direction, &tmp_vector) - dir_dot_axis * (x_dot_axis + 2 * data->radius));
	k[2] = vector3_dot(&tmp_vector, &tmp_vector) - x_dot_axis * (x_dot_axis + 4 * data->radius);
	if ((discriminant = k[1] * k[1] - 4 * k[0] * k[2]) < 0.)
		return (0);
	t = (-k[1] - sqrtf(discriminant)) / (2 * k[0]);
	if (t <= RAY_T_MIN || t >= intersection->ray.t)
		return (0);
	intersection->ray.t = t;
	tmp_vector = vector3_s_add(intersection->ray.origin, vector3_mul(&intersection->ray.direction, t));
	temp_value = vector3_s_dot(data->normal, vector3_sub(&tmp_vector, &data->extremum_point));
	intersection->normal = vector3_s_sub(vector3_sub(&tmp_vector, &data->extremum_point), vector3_mul(&data->normal, temp_value));
	vector3_normalize(&intersection->normal);
	intersection->color = shape->material->color;
	intersection->material = shape->material;
	intersection->highlight = &shape->highlight;
	return (1);
}

t_shape						*shape_paraboloid(t_vector3 extremum_point, t_vector3 normal, double radius, t_material *material)
{
	t_shape					*shape;
	t_shape_data_paraboloid	*data;

	if (!(shape = (t_shape *)malloc(sizeof(t_shape))))
		exit(21);
	if (!(data = (t_shape_data_paraboloid *)malloc(sizeof(t_shape_data_paraboloid))))
		exit(21);
	data->extremum_point = extremum_point;
	data->normal = vector3_s_normalize(normal);
	data->radius = radius;
	shape->material = material;
	shape->data = (void *)data;
	shape->intersect = paraboloid_intersect;
	shape->highlight = 0;
	return (shape);
}

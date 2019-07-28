#include "shape_list.h"


static double 		cylinder_caps_intersect(t_shape *shape, t_intersection *intersection)
{
	t_cylinder_data	*data;
	double 			t[2];

	data = (t_cylinder_data *)shape->data;
	if (!vector3_dot(&intersection->ray.direction, &data->axis))
		return (INFINITY);
	t[0] = vector3_s_dot(vector3_sub(&data->top, &intersection->ray.origin), data->axis) / vector3_dot(&intersection->ray.direction, &data->axis);
	if (t[0] <= RAY_T_MIN)
		return (INFINITY);
	if (vector3_s_length(vector3_s_sub(data->top, vector3_s_add(intersection->ray.origin, vector3_mul(&intersection->ray.direction, t[0])))) < data->radius)
		intersection->normal = data->axis;
	else
		t[0] = INFINITY;
	t[1] = vector3_s_dot(vector3_sub(&data->bottom, &intersection->ray.origin), data->axis) / vector3_dot(&intersection->ray.direction, &data->axis);
	if (t[1] <= RAY_T_MIN)
		return (INFINITY);
	if (vector3_s_length(vector3_s_sub(data->bottom, vector3_s_add(intersection->ray.origin, vector3_mul(&intersection->ray.direction, t[1])))) < data->radius && t[1] < t[0])
		intersection->normal = vector3_mul(&data->axis, -1);
	else
		return (t[0]);
	return (t[1]);
}

int 			cylinder_intersect
	(t_shape *shape, t_intersection *intersection)
{
	t_cylinder_data	*data;
	double 			k[3];
	double 			discriminant;
	double 			t[2];
	t_vector3		temp[2];
	double 			angle[2];

	data = (t_cylinder_data *)shape->data;
	temp[0] = vector3_sub(&intersection->ray.origin, &data->bottom);
	k[0] = vector3_dot(&intersection->ray.direction, &intersection->ray.direction) - pow(vector3_dot(&intersection->ray.direction, &data->axis), 2.);
	k[1] = 2 * (vector3_dot(&intersection->ray.direction, temp) - vector3_dot(&intersection->ray.direction, &data->axis) *  vector3_dot(temp, &data->axis));
	k[2] =  vector3_dot(temp, temp) - pow(vector3_dot(temp, &data->axis), 2.) - pow(data->radius, 2.);
	if ((discriminant = k[1] * k[1] - 4 * k[0] * k[2]) < 0.)
		return (0);
	t[0] = (-k[1] - sqrtf(discriminant)) / (2 * k[0]);
	if (t[0] <= RAY_T_MIN || t[0] >= intersection->ray.t)
		return (0);
	temp[0] = vector3_s_add(intersection->ray.origin, vector3_mul(&intersection->ray.direction, t[0]));	// p
	angle[0] = vector3_s_dot(vector3_sub(temp, &data->top), data->axis);
	angle[1] = vector3_s_dot(vector3_sub(temp, &data->bottom), data->axis);
	t[1] = cylinder_caps_intersect(shape, intersection);
	if ((angle[0] > 0. || angle[1] < 0.) && t[1] != INFINITY)
		t[0] = t[1];
	else if (!(angle[0] > 0. || angle[1] < 0.))
	{
		temp[1] = vector3_sub(temp, &data->bottom); // p - b
		intersection->normal = vector3_s_sub(temp[1], vector3_mul(&data->axis, vector3_dot(temp + 1, &data->axis)));
	}
	else
		return (0);
	intersection->ray.t = t[0];
	intersection->color = shape->material->color;
	intersection->material = shape->material;
	intersection->highlight = &shape->highlight;
	return (1);
}

static void			cylinder_move(t_shape *shape, t_vector3 move)
{
	t_cylinder_data	*data;

	data = (t_cylinder_data *)shape->data;
	vector3_add_eq(&data->top, &move);
	vector3_add_eq(&data->bottom, &move);
}

t_shape				*shape_cylinder
	(t_vector3 top, t_vector3 bottom, double radius, const t_material *material)
{
	t_shape			*shape;
	t_cylinder_data	*data;

	if (!(shape = (t_shape *)malloc(sizeof(t_shape))))
		exit(21);
	if (!(data = (t_cylinder_data *)malloc(sizeof(t_cylinder_data))))
		exit(21);
	data->top = top;
	data->bottom = bottom;
	data->radius = radius;
	data->axis = vector3_s_normalize(vector3_sub(&top, &bottom));
	shape->material = material;
	shape->data = (void *)data;
	shape->data_size = sizeof(t_cylinder_data);
	shape->intersect = cylinder_intersect;
	shape->move = cylinder_move;
	shape->highlight = 0;
	return (shape);
}


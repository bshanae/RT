#include "shape_list.h"

static double       cone_cap_intersect(t_shape *shape, t_intersection *intersection)
{
	t_cone_data	*data;
	double 			t;

	data = (t_cone_data *)shape->data;
	if (!vector3_dot(&intersection->ray.direction, &data->axis))
		return (INFINITY);
	t = vector3_s_dot(vector3_sub(&data->bottom, &intersection->ray.origin), data->axis) / vector3_dot(&intersection->ray.direction, &data->axis);
	if (t <= RAY_T_MIN)
		return (INFINITY);
	if (vector3_s_length(vector3_s_sub(data->bottom, vector3_s_add(intersection->ray.origin, vector3_mul(&intersection->ray.direction, t)))) < data->radius)
		intersection->normal = vector3_mul(&data->axis, -1);
	else
		return (INFINITY);
	return (t);

}

int 				cone_intersect
		(t_shape *shape, t_intersection *intersection)
{
	t_cone_data	    *data;
	double 			k[3];
	double 			discriminant;
	double 			t[2];
	t_vector3		temp[3];
	double 			angle[2];

	data = (t_cone_data *)shape->data;
	temp[0] = vector3_sub(&intersection->ray.origin, &data->top);
	k[0] = vector3_dot(&intersection->ray.direction, &intersection->ray.direction) - pow(vector3_dot(&intersection->ray.direction, &data->axis), 2.) * (1 + data->tangens * data->tangens);
	k[1] = 2 * (vector3_dot(temp, &intersection->ray.direction) - (1 + data->tangens * data->tangens) * vector3_dot(&intersection->ray.direction, &data->axis) * vector3_dot(temp, &data->axis));
	k[2] = vector3_dot(temp, temp) - (1 + data->tangens * data->tangens) * pow(vector3_dot(temp, &data->axis), 2.);
	if ((discriminant = k[1] * k[1] - 4 * k[0] * k[2]) < 0.)
		return (0);
	t[0] = (-k[1] - sqrtf(discriminant)) / (2 * k[0]);
	if (t[0] <= RAY_T_MIN || t[0] >= intersection->ray.t)
		return (0);
	temp[1] = vector3_s_add(intersection->ray.origin, vector3_mul(&intersection->ray.direction, t[0])); // p
	temp[2] = vector3_sub(temp + 1, &data->bottom);
	angle[0] = vector3_s_dot(vector3_sub(temp + 1, &data->top), data->axis);
	angle[1] = vector3_s_dot(vector3_sub(temp + 1, &data->bottom), data->axis);
	int is_inf = (vector3_s_length(temp[2]) > vector3_s_length(vector3_sub(&data->top, &data->bottom)) || vector3_dot(temp + 2, &data->axis) > 0.);
	t[1] = cone_cap_intersect(shape, intersection);
	if (t[1] != INFINITY && is_inf)
		t[0] = t[1];
	else if (!is_inf)
	{
		t[1] = vector3_dot(&intersection->ray.direction, &data->axis) * t[0] + vector3_dot(temp, &data->axis);
		intersection->normal = vector3_s_sub(vector3_s_sub(temp[1], data->top), vector3_s_mul(data->axis, (1 + data->tangens * data->tangens) * t[1]));
		vector3_normalize(&intersection->normal);
	}
	else
		return (0);
	intersection->ray.t = t[0];
	intersection->color = shape->material->color;
	intersection->material = shape->material;
	intersection->highlight = &shape->highlight;
	return (1);
}

static void			cone_move(t_shape *shape, t_vector3 move)
{
	t_cone_data		*data;

	data = (t_cone_data *)shape->data;
	vector3_add_eq(&data->top, &move);
	vector3_add_eq(&data->bottom, &move);
}

t_shape				*shape_cone
		(t_vector3 top, t_vector3 bottom, double tangens, const t_material *material)
{
	t_shape			*shape;
	t_cone_data	    *data;

	if (!(shape = (t_shape *)malloc(sizeof(t_shape))))
		exit(21);
	if (!(data = (t_cone_data *)malloc(sizeof(t_cone_data))))
		exit(21);
	data->top = top;
	data->bottom = bottom;
	data->axis = vector3_sub(&bottom, &top);
	data->tangens = tan(tangens * M_PI / 180);
	data->radius = data->tangens * vector3_s_length(data->axis);
	data->axis = vector3_s_normalize(data->axis);
	shape->material = material;
	shape->data = (void *)data;
	shape->data_size = sizeof(t_cone_data);
	shape->intersect = cone_intersect;
	shape->move = cone_move;
	shape->highlight = 0;
	return (shape);
}
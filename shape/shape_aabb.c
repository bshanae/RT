#include "shape_list.h"

int 			aabb_intersect
	(t_shape *shape, t_intersection *intersection)
{
	t_aabb_data		*data;
	double			inv_dir;
	double 			t[2];
	double 			t_near;
	double 			t_far;
	int 			i;
	t_vector3		normal;

	data = (t_aabb_data *)shape->data;
	i = 0;
	t_near = RAY_T_MIN;
	t_far = RAY_T_MAX;
	while (i < 3)
	{
		inv_dir = 1. / *vector3_iter(&intersection->ray.direction, i);
		t[0] = (*vector3_iter(&data->min, i) - *vector3_iter(&intersection->ray.origin, i)) * inv_dir;
		t[1] = (*vector3_iter(&data->max, i) - *vector3_iter(&intersection->ray.origin, i)) * inv_dir;
		if (inv_dir < 0.)
			swap_memory(t, t + 1, sizeof(double));
		if ((t_near = fmax(t[0], t_near)) == t[0])
		{
			normal = (t_vector3){0., 0., 0.};
			*vector3_iter(&normal, i) = inv_dir < 0. ? 1. : -1.;
		}
		t_far = fmin(t[1], t_far);
		if (t_far <= t_near)
			return (0);
		i++;
	}
	if (t_near == RAY_T_MIN || t_near >= intersection->ray.t)
		return (0);
	intersection->ray.t = t_near;
	intersection->normal = normal;
	intersection->color = shape->material->color;
	intersection->material = shape->material;
	intersection->highlight = &shape->highlight;
	return (1);

}

static void			aabb_move(t_shape *shape, t_vector3 move)
{
	t_aabb_data		*data;

	data = (t_aabb_data *)shape->data;
	vector3_add_eq(&data->min, &move);
	vector3_add_eq(&data->max, &move);
}


t_shape				*shape_aabb
		(t_vector3 min, t_vector3 max, t_material *material)
{
	t_shape			*shape;
	t_aabb_data		*data;

	if (!(shape = (t_shape *)malloc(sizeof(t_shape))))
		exit(21);
	if (!(data = (t_aabb_data *)malloc(sizeof(t_aabb_data))))
		exit(21);
	data->max = max;
	data->min = min;
	shape->material = material;
	shape->data = (void *)data;
	shape->data_size = sizeof(t_aabb_data);
	shape->intersect = aabb_intersect;
	shape->move = aabb_move;
	shape->highlight = 0;
	return (shape);
}

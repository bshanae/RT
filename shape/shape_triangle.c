#include "shape_list.h"

int							shape_intersect_triangle(t_shape *shape, t_intersection *intersection)
{
	t_shape_data_triangle	*data;
	t_vector3				ab;
	t_vector3				ac;
	t_vector3				p_v;
	t_vector3				t_v;
	t_vector3				q_v;
	float					u;
	float					v;
	float					t;
	float					determinant;
	float					inverse_determinant;

	data = (t_shape_data_triangle *)shape->data;
	ab = vector3_sub_ref(&data->b, &data->a);
	ac = vector3_sub_ref(&data->c, &data->a);

	p_v = vector3_cross_ref(&intersection->ray.direction, &ac);
	determinant = vector3_dot_ref(&ab, &p_v);

	if (determinant < INTERSECTION_MIN)
		return (0);
	if (fabsf(determinant) < INTERSECTION_MIN)
		return (0);

	inverse_determinant = 1.f / determinant;

	t_v = vector3_sub_ref(&intersection->ray.origin, &data->a);
	u = vector3_dot_ref(&t_v, &p_v) * inverse_determinant;
	if (u < 0. || u > 1.)
		return (0);

	q_v = vector3_cross_ref(&t_v, &ab);
	v = vector3_dot_ref(&intersection->ray.direction, &q_v) * inverse_determinant;
	if (v < 0 || u + v > 1.)
		return (0);

	t = vector3_dot_ref(&ac, &q_v) * inverse_determinant;
	if (t >= intersection->ray.t)
		return (0);

	intersection->ray.t = t;
	intersection->normal = vector3_cross_ref(&ab, &ac);
	vector3_normalize(&intersection->normal);
	intersection->material = shape->material;
	intersection->hit = ray_calculate(&intersection->ray);
	return (1);
}

t_shape						shape_triangle(t_vector3 a, t_vector3 b, t_vector3 c, t_material material)
{
	t_shape					shape;
	t_shape_data_triangle	*data;

	data = (t_shape_data_triangle *)shape.data;
	data->a = a;
	data->b = b;
	data->c = c;
	shape.id = SHAPE_ID_TRIANGLE;
	shape.material = material;
	return (shape);
}

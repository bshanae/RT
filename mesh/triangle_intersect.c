#include "triangle.h"

int 				triangle_intersect(const t_triangle *triangle, t_intersection *intersection)
{
	t_vector3		ab;
	t_vector3		ac;
	t_vector3		p_v;
	t_vector3		t_v;
	t_vector3		q_v;
	float			u;
	float			v;
	float			t;
	float			determinant;
	float			inverse_determinant;

	ab = vector3_sub_ref(&triangle->b, &triangle->a);
	ac = vector3_sub_ref(&triangle->c, &triangle->a);

	p_v = vector3_cross_ref(&intersection->ray.direction, &ac);
	determinant = vector3_dot_ref(&ab, &p_v);

	if (fabsf(determinant) < INTERSECTION_MIN)
		return (0);

	inverse_determinant = 1.f / determinant;

	t_v = vector3_sub_ref(&intersection->ray.origin, &triangle->a);
	u = vector3_dot_ref(&t_v, &p_v) * inverse_determinant;
	if (u < 0. || u > 1.)
		return (0);

	q_v = vector3_cross_ref(&t_v, &ab);
	v = vector3_dot_ref(&intersection->ray.direction, &q_v) * inverse_determinant;
	if (v < 0 || u + v > 1.)
		return (0);

	t = vector3_dot_ref(&ac, &q_v) * inverse_determinant;
	if (t < INTERSECTION_MIN || t > intersection->ray.t)
		return (0);
//	printf("%f %f\n", t, intersection->ray.t);
	intersection->ray.t = t;
	intersection->normal = triangle->normal;
	return (1);
}
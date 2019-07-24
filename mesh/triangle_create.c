#include "triangle.h"

static t_vector3	triangle_normal(t_triangle *triangle)
{
	t_vector3		ba;
	t_vector3		ca;

	ba = vector3_sub_ref(&triangle->b , &triangle->a);
	ca = vector3_sub_ref(&triangle->c , &triangle->a);
	return (vector3_cross_ref(&ba, &ca));
}

t_triangle			triangle_create(VECTOR3_REF a, VECTOR3_REF b, VECTOR3_REF c, VECTOR3_REF normal)
{
	t_triangle		triangle;

	triangle.a = vector3_mul_ref(a, MESH_RESIZE_RATIO);
	triangle.b = vector3_mul_ref(b, MESH_RESIZE_RATIO);
	triangle.c = vector3_mul_ref(c, MESH_RESIZE_RATIO);
	if (normal)
		triangle.normal = *normal;
	else
		triangle.normal = triangle_normal(&triangle);
	triangle.center = (t_vector3)
		{
			(triangle.a.x + triangle.b.x + triangle.c.x) / 3.,
			(triangle.a.y + triangle.b.y + triangle.c.y) / 3.,
			(triangle.a.z + triangle.b.z + triangle.c.z) / 3.
		};
	return (triangle);
}
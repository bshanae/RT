#include "triangle.h"

t_triangle			triangle_create(VECTOR3_REF a, VECTOR3_REF b, VECTOR3_REF c, VECTOR3_REF normal)
{
	t_triangle		triangle;

	triangle.a = vector3_mul_ref(a, 10.f);
	triangle.b = vector3_mul_ref(b, 10.f);
	triangle.c = vector3_mul_ref(c, 10.f);
	triangle.normal = *normal;
	return (triangle);
}
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

	triangle.a = *a;
	triangle.b = *b;
	triangle.c = *c;
	vector3_rotate_x(&triangle.a, MESH_ROTATE_X);
	vector3_rotate_x(&triangle.b, MESH_ROTATE_X);
	vector3_rotate_x(&triangle.c, MESH_ROTATE_X);
	vector3_rotate_y(&triangle.a, MESH_ROTATE_Y);
	vector3_rotate_y(&triangle.b, MESH_ROTATE_Y);
	vector3_rotate_y(&triangle.c, MESH_ROTATE_Y);
	triangle.a = vector3_add_cp(vector3_mul_ref(&triangle.a, MESH_RESIZE), MESH_SHIFT);
	triangle.b = vector3_add_cp(vector3_mul_ref(&triangle.b, MESH_RESIZE), MESH_SHIFT);
	triangle.c = vector3_add_cp(vector3_mul_ref(&triangle.c, MESH_RESIZE), MESH_SHIFT);
	if (normal)
		triangle.normal = *normal;
	else
		triangle.normal = triangle_normal(&triangle);
	triangle.min = vector3_min_vector(&triangle.a, &triangle.b);
	triangle.min = vector3_min_vector(&triangle.min, &triangle.c);
	triangle.max = vector3_max_vector(&triangle.a, &triangle.b);
	triangle.max = vector3_max_vector(&triangle.max, &triangle.c);
	return (triangle);
}
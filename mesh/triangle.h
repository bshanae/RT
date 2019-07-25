#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "options.h"

# include "vector3.h"
# include "intersection.h"

typedef struct		s_triangle
{
	t_vector3		a;
	t_vector3		b;
	t_vector3		c;
	t_vector3		normal;
	t_vector3		min;
	t_vector3		max;
}					t_triangle;

t_triangle			triangle_create(VECTOR3_REF a, VECTOR3_REF b, VECTOR3_REF c, VECTOR3_REF normal);

int 				triangle_intersect(const t_triangle *triangle, t_intersection *intersection);

#endif

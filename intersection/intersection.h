#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "material.h"
# include "vector3.h"

typedef struct 		s_intersection
{
	t_vector3		direction;
	t_vector3		origin;
	float 			t;
	t_vector3		hit;
	t_vector3		normal;
	t_material		material;
}					t_intersection;

t_vector3			intersection_calculate(t_intersection *intersection);

#endif

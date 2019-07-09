#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "vector3.h"
# include "shape.h"

typedef struct 		s_intersection
{
	t_vector3		ray;
	float 			t;
	t_vector3		normal;
	int 			material_id;
}					t_intersection;

#endif

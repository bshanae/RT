#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "ray.h"

typedef struct		s_intersection
{
	t_ray			ray;
	t_vector3		hit;
	t_vector3		normal;
	int 			object_id;
}					t_intersection;

#endif

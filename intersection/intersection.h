#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "ray.h"

typedef struct		s_intersection
{
	t_ray			ray;
	cl_double4		hit;
	cl_double4		normal;
	int 			object_id;
}					t_intersection;

#endif

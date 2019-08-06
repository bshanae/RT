#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "ray.h"

typedef struct		s_intersection
{
	t_ray			ray;
	API_FLOAT4		hit;
	API_FLOAT4		normal;
	int 			object_id;
}					t_intersection;

#endif

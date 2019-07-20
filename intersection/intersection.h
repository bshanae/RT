#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "material.h"
# include "vector3.h"
# include "ray.h"

typedef struct 		s_intersection
{
	t_ray			ray;
	t_vector3		hit;
	t_vector3		normal;
	t_material		material;
	int 			shape_index;
}					t_intersection;

void				intersection_reflect(t_intersection *destination, const t_intersection *source);

void				intersection_refract(t_intersection *destination, const t_intersection *source);

#endif

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "ray.h"
# include "light.h"
# include "material.h"

typedef struct			s_intersection
{
	t_ray				ray;
	t_vector3			normal;
    float         		diffuse_intensity;
	float         		specular_intensity;
	t_vector3           color;
	t_material			material;
	float 				shadow_ratio;
	int 				highlight;
}						t_intersection;

#endif

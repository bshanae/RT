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
}						t_intersection;

void					intersection_reset(t_intersection *me);

t_vector3           	intersection_light_direction(t_intersection *intersection, t_light *light);

void                	intersection_lighting_diffuse(t_intersection *intersection, t_light *light, t_vector3 *light_direction);

void                	intersection_lighting_specular(t_intersection *intersection, t_light *light, t_vector3 *light_direction);

void                	intersection_make_color(t_intersection *intersection);

#endif

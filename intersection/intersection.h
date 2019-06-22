#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "ray.h"
# include "light.h"
# include "material.h"

# define BLINN_ALPHA	60.

typedef struct			s_intersection
{
	t_ray				ray;
	t_vector3			normal;
    FLOAT_MACRO         diffuse_intensity;
	FLOAT_MACRO         specular_intensity;
	t_vector3           color;
	const t_material	*material;
	FLOAT_MACRO 				shadow_ratio;
	int 				*highlight;
}						t_intersection;

typedef struct			s_intersection_cl
{
	t_ray				ray;
	t_vector3			normal;
	FLOAT_MACRO         diffuse_intensity;
	FLOAT_MACRO         specular_intensity;
	t_vector3           color;
	t_material			material;
	FLOAT_MACRO 		shadow_ratio;
	int 				highlight;
}						t_intersection_cl;

void					intersection_reset(t_intersection *me);

void					intersection_reflect(t_intersection *target, const t_intersection *source);

void					intersection_refract(t_intersection *target, const t_intersection *source);

t_vector3               intersection_light_direction(t_intersection *intersection, t_light *light);

void                    intersection_lighting_diffuse(t_intersection *intersection, t_light *light, t_vector3 *light_direction);

void                    intersection_lighting_specular(t_intersection *intersection, t_light *light, t_vector3 *light_direction);

void                    intersection_make_color(t_intersection *intersection);

#endif

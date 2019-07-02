#ifndef RAY_H
# define RAY_H

# include "vector3.h"

# define RAY_T_MIN	0.001f
# define RAY_T_MAX	INFINITY

typedef	struct		s_ray
{
	t_vector3		origin;
	t_vector3		direction;
	float 			t;
}					t_ray;

t_vector3			ray_intersect(const t_ray *me);

#endif

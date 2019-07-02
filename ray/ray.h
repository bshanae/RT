#ifndef RAY_H
# define RAY_H

# include "vector3.h"

# if float == float
#  define RAY_T_MIN 0.001f
# elif float == double
#  define RAY_T_MIN 0.000001
# endif

# define RAY_T_MAX	INFINITY

typedef	struct		s_ray
{
	t_vector3		origin;
	t_vector3		direction;
	float 			t;
}					t_ray;

t_vector3			ray_intersect(const t_ray *me);

#endif

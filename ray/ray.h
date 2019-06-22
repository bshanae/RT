#ifndef RAY_H
# define RAY_H

# include "vector3.h"

# if FLOAT_MACRO == float
#  define RAY_T_MIN 0.001f
# elif FLOAT_MACRO == double
#  define RAY_T_MIN 0.000001
# endif

# define RAY_T_MAX	INFINITY

typedef	struct		s_ray
{
	t_vector3		origin;
	t_vector3		direction;
	FLOAT_MACRO 			t;
}					t_ray;

t_vector3			ray_intersect(const t_ray *me);

#endif

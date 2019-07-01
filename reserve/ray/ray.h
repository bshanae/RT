#ifndef RAY_H
# define RAY_H

# include "vector3.h"

typedef	struct		s_ray
{
	t_vector3		origin;
	t_vector3		direction;
	float 			t;
}					t_ray;

#endif

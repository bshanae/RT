#ifndef RAY_H
# define RAY_H

# include "cl_include.h"

typedef	struct		s_ray
{
	cl_double4		origin;
	cl_double4		direction;
	double 			t;
}					t_ray;

#endif

#ifndef RAY_H
# define RAY_H

# include "cl_include.h"
# include "cl_float.h"

typedef	struct		s_ray
{
	API_FLOAT4		origin;
	API_FLOAT4		direction;
	FLOAT			t;
}					t_ray;

#endif

#ifndef F2_H
# define F2_H

# include <OpenCL/opencl.h>

# include "rt_float.h"

double 				f2_dot(RT_F2_API a, RT_F2_API b);

RT_F2_API			f2_mul_components(RT_F2_API a, RT_F2_API b);

RT_F2_API			f2_mul(const RT_F2_API a, double value);

RT_F2_API			f2_add(RT_F2_API a, RT_F2_API b);

RT_F2_API			f2_sub(RT_F2_API a, RT_F2_API b);

#endif

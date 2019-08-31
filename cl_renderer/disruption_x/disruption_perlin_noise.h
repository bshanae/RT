#ifndef DISRUPTION_PERLIN_NOISE_H
# define DISRUPTION_PERLIN_NOISE_H

#include <OpenCL/opencl.h>

#include "rt_float.h"

# define FRACT(x) x - floor(x)

double			lerp(double a, double b, double t);

double			quantic_curve(double t);

RT_F2_API		hash(RT_F2_API x);

#endif

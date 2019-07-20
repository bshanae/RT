#include "filter.h"

static void			normalize_value(float *f)
{
	if (*f < 1.)
		*f = sqrtf(*f) - 1;
	else
		*f = 1. - sqrtf(2. - *f);
}

void 				filter_jitter_values(float *x, float *y)
{
	float 			dx;
	float 			dy;

	dx = 2. * drand48();
	dy = 2. * drand48();
	normalize_value(&dx);
	normalize_value(&dy);
	*x += dx;
	*y += dy;
}
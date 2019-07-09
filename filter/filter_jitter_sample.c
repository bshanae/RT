#include "filter.h"

static void			normalize_value(float *f)
{
	if (*f < 1.)
		*f = sqrtf(*f) - 1;
	else
		*f = 1. - sqrtf(2. - *f);
}

void 				filter_jitter_sample(t_vector3 *ray)
{
	t_vector3		u;

	srand48(time(NULL));
	u.x = 2. * drand48();
	u.y = 2. * drand48();
	u.z = 0;
	normalize_value(&u.x);
	normalize_value(&u.y);
	vector3_add_eq_ref(ray, &u);
}
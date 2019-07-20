#include "sampler.h"

t_vector3			sampler_uniform(VECTOR3_REF normal, float *cosine)
{
	float 			r[2];
	t_vector3		sample;

	r[0] = drand48();
	r[1] = drand48();
	float sin_theta = sqrtf(fmaxf(0.0f , 1.0f - r[0] * r[0]));
	float phi = 2.0f * M_PI * r[1];
	if(cosine)
		*cosine = r[0];
	sample = (t_vector3)
		{
			sin_theta * cosf(phi),
			r[0],
			sin_theta * sinf(phi)
		};
	return (sampler_transform(normal, &sample));
}
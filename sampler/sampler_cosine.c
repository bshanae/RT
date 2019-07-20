#include "sampler.h"

t_vector3			sampler_cosine(VECTOR3_REF normal)
{
	float 			r[2];
	t_vector3		sample;

	float cos_theta = sqrtf(fmaxf(0.0f , 1.0f - r[0]));
	float sin_theta = sqrtf(fmaxf(0.0f , 1.0f - cos_theta * cos_theta));
	float phi = 2.0f * M_PI * r[1];

	sample = (t_vector3)
		{
			sin_theta * cosf(phi),
			cos_theta,
			sin_theta * sinf(phi)
		};
	return (sampler_transform(normal, &sample));
}
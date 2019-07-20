#include "sampler.h"

static void				create_coordinate_system(const t_vector3 *normal, t_vector3 *nt, t_vector3 *nb)
{
	if (fabsf(normal->x) > fabsf(normal->y))
		*nt = (t_vector3){normal->z, 0., -1.f * normal->x};
	else
		*nt = (t_vector3){0., -1.f * normal->z, normal->y};
	vector3_normalize(nt);
	*nb = vector3_cross_ref(normal, nt);
}

static t_vector3		generate_sample(const float *r1, const float *r2, float *cosine)
{
	float sin_theta = sqrtf(fmaxf(0.0f , 1.0f - *r1 * *r1));
	float phi = 2.0f * M_PI * *r2;
	*cosine = *r1;

	return (t_vector3)
	{
		sin_theta * cosf(phi),
		*r1,
		sin_theta * sinf(phi)
	};
}

static t_vector3		convert_sample(const t_vector3 *normal, const t_vector3 *sample, const t_vector3 *nt, const t_vector3 *nb)
{
	return ((t_vector3)
	{
		sample->x * nb->x + sample->y * normal->x + sample->z * nt->x,
		sample->x * nb->y + sample->y * normal->y + sample->z * nt->y,
		sample->x * nb->z + sample->y * normal->z + sample->z * nt->z,
	});
}

t_vector3				sampler_uniform(const t_vector3 *normal, float *cosine)
{
	t_vector3			nt;
	t_vector3			nb;
	float 				r[2];
	t_vector3			sample;

	create_coordinate_system(normal, &nt, &nb);
	r[0] = drand48();
	r[1] = drand48();
	sample = generate_sample(r, r + 1, cosine);
	sample = convert_sample(normal, &sample, &nt, &nb);
	return (sample);
}
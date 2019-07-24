#include "sampler.h"

static void				create_coordinate_system(VECTOR3_REF normal, t_vector3 *nt, t_vector3 *nb)
{
	if (fabsf(normal->x) > fabsf(normal->y))
		*nt = (t_vector3){normal->z, 0., -1.f * normal->x};
	else
		*nt = (t_vector3){0., -1.f * normal->z, normal->y};
	vector3_normalize(nt);
	*nb = vector3_cross_ref(normal, nt);
}

static t_vector3		convert_sample(VECTOR3_REF normal, VECTOR3_REF sample, VECTOR3_REF nt, VECTOR3_REF nb)
{
	return ((t_vector3)
		{
			sample->x * nb->x + sample->y * normal->x + sample->z * nt->x,
			sample->x * nb->y + sample->y * normal->y + sample->z * nt->y,
			sample->x * nb->z + sample->y * normal->z + sample->z * nt->z,
		});
}

t_vector3				sampler_transform(VECTOR3_REF normal, VECTOR3_REF sample)
{
	t_vector3			nt;
	t_vector3			nb;

	create_coordinate_system(normal, &nt, &nb);
	return (convert_sample(normal, sample, &nt, &nb));
}
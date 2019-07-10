#include "vector3.h"

void					vector3_normalize(t_vector3 *v)
{
	float 				inverse_length;

	inverse_length = 1. / vector3_length_ref(v);
	v->x *= inverse_length;
	v->y *= inverse_length;
	v->z *= inverse_length;
}

t_vector3				vector3_normalized_ref(VECTOR3_REF v)
{
	float 				inverse_length;

	inverse_length = 1. / vector3_length_ref(v);
	return ((t_vector3)
	{
		.x = v->x * inverse_length,
		.y = v->y * inverse_length,
		.z = v->z * inverse_length
	});
}

t_vector3				vector3_normalized_cp(t_vector3 v)
{
	float 				inverse_length;

	inverse_length = 1. / vector3_length_ref(&v);
	return ((t_vector3)
	{
			.x = v.x * inverse_length,
			.y = v.y * inverse_length,
			.z = v.z * inverse_length
	});
}


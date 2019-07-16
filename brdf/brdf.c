#include "brdf.h"

float 				GGX_Geometry(const float *theta_cosine, const float *alpha)
{
	float 			theta_cosine_squared;
	float 			theta_tangent_squared;

	theta_cosine_squared = *theta_cosine * *theta_cosine;
	theta_tangent_squared = (1 - theta_cosine_squared) / theta_cosine_squared;
	return (2 / (1. + sqrtf(1. + powf(*alpha, 4.) * theta_tangent_squared)));
}

float 				GGX_Distribution(const float *theta_cosine, const float *alpha)
{
	float 			theta_cosine_squared;
	float 			theta_tangent_squared;

	theta_cosine_squared = *theta_cosine * *theta_cosine;
	theta_tangent_squared = (1. - theta_cosine_squared) / theta_cosine_squared;
	return (powf(*alpha, 4.) / (M_PI * powf(*theta_cosine, 4.) * powf(powf(*alpha, 4.) + theta_tangent_squared , 2.)));
}

float 				GGX_Fresnel(const float *ratio, const float *theta_cosine)
{
	return (*ratio + (1. - *ratio) * pow(1. - *theta_cosine, 5.));
}

float 				brdf(const t_intersection *intersection, const t_vector3 *sample)
{
	t_vector3		n;
	t_vector3		h;
	t_vector3		v;
	t_vector3		l;

	float 			nl;
	float 			nv;
	float 			nh;
	float 			hv;

	float 			roughness;
	float 			fresnel_ratio;

	float 			G;
	float 			D;
	float 			F;

	n = intersection->normal;
	v = vector3_mul_ref(&intersection->ray.direction, -1.);
	l = *sample;

	h = vector3_add_ref(&v, &l);
	vector3_normalize(&h);

	nl = vector3_dot_ref(&n, &l);
	if (nl < 0.)
		return (0.);

	nv = vector3_dot_ref(&n, &v);
	if (nv < 0.)
		return (0.);

	nh = vector3_dot_ref(&n, &h);
	hv = vector3_dot_ref(&h, &v);

	roughness = .9;
	fresnel_ratio = .1;

	G = GGX_Geometry(&nv, &roughness) * GGX_Geometry(&nl, &roughness);
	D = GGX_Distribution(&nh, &roughness);
	F = GGX_Fresnel(&fresnel_ratio, &hv);

	return ((1. - F) * DEFAULT_ALBEDO * M_1_PI + (G * D * F) / (4. * nv));
}
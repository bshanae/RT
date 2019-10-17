/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disruption_perlin_noise.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:02:41 by ashari            #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disruption.h"

static RT_F2_API		compute_dot(RT_F4_API *value, double fx, double fy)
{
	RT_F2_API			integer_values;
	RT_F2_API			fractional_values;

	integer_values = (RT_F2_API){floor(fx), floor(fy)};
	fractional_values = (RT_F2_API)
			{fx - integer_values.x, fy - integer_values.y};
	value->x = f2_dot(hash(f2_add(integer_values, (RT_F2_API){0., 0.})),
					f2_sub(fractional_values, (RT_F2_API){0., 0.}));
	value->y = f2_dot(hash(f2_add(integer_values, (RT_F2_API){1., 0.})),
					f2_sub(fractional_values, (RT_F2_API){1., 0.}));
	value->z = f2_dot(hash(f2_add(integer_values, (RT_F2_API){0., 1.})),
					f2_sub(fractional_values, (RT_F2_API){0., 1.}));
	value->w = f2_dot(hash(f2_add(integer_values, (RT_F2_API){1., 1.})),
					f2_sub(fractional_values, (RT_F2_API){1., 1.}));
	return (fractional_values);
}

static double			compute_perlin_noise(double fx, double fy)
{
	RT_F4_API			interpolation_result;
	RT_F4_API			dot;
	RT_F2_API			u;
	RT_F2_API			fractional_values;

	fractional_values = compute_dot(&dot, fx, fy);
	u = f2_mul_components(fractional_values, fractional_values);
	interpolation_result.x = lerp(dot.x, dot.y, quantic_curve(u.x));
	interpolation_result.y = lerp(dot.z, dot.w, quantic_curve(u.x));
	interpolation_result.z = lerp(interpolation_result.x,
			interpolation_result.y, quantic_curve(u.y));
	return (interpolation_result.z);
}

static double			choose_perlin_noise(double x, double y)
{
	double				amplitude;
	double				result;
	double				sum_amplitude;
	int					i;

	x *= 4.;
	y *= 4.;
	i = 0;
	amplitude = 1.;
	result = 0.;
	sum_amplitude = 0.;
	while (i++ < 15)
	{
		result += amplitude * fabs(compute_perlin_noise(x, y));
		sum_amplitude += amplitude;
		x *= 2.;
		y *= 2.;
		amplitude *= .5;
	}
	return (result / sum_amplitude);
}

RT_F4_API				disruption_perlin_noise(double x, double y)
{
	double				perlin_result;
	RT_F2_API			uv;

	uv = (RT_F2_API){x / DISRUPTION_WIDTH, y / DISRUPTION_HEIGHT};
	uv.x *= (double)DISRUPTION_WIDTH / DISRUPTION_HEIGHT;
	perlin_result = choose_perlin_noise(uv.x, uv.y);
	perlin_result = 0.4 + 0.9 * perlin_result;
	return ((RT_F4_API){perlin_result, perlin_result, perlin_result, 1.});
}

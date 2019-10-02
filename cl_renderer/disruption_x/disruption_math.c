/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disruption_math.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:02:35 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disruption.h"

double			lerp(double a, double b, double t)
{
	return (a + t * (b - a));
}

double			quantic_curve(double t)
{
	return (t * t * t * (t * (t * 6 - 15) + 10));
}

RT_F2_API		hash(RT_F2_API x)
{
	RT_F2_API	k;
	RT_F2_API	tmp;

	k = (RT_F2_API) {0.3183099, 0.3678794};
	x = f2_mul_components(x, k);
	x.x += k.y;
	x.y += k.x;
	k = f2_mul(k, 16. * FRACT(sin(x.x) * sin(x.y) * (x.x + x.y)));
	tmp = f2_mul((RT_F2_API){FRACT(k.x), FRACT(k.y)}, 2.);
	return ((RT_F2_API){tmp.x - 1., tmp.y - 1.});
}

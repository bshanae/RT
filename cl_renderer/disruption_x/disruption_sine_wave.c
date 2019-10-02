/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disruption_sine_wave.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:02:55 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disruption.h"

static void			recalculate_values(double *x, double *y)
{
	*x = *x / DISRUPTION_WIDTH + sin(TAU);
	*y = *y / DISRUPTION_HEIGHT + cos(TAU);
}

RT_F4_API			disruption_sine_wave(double x, double y)
{
	RT_F4_API		color;

	recalculate_values(&x, &y);
	x *= (double)DISRUPTION_WIDTH / DISRUPTION_HEIGHT;
	x += sin(y * 3.) / 10.;
	y += sin(x * 4.) / 5.;
	if (fmod(y + y, .2) <= 0.1)
		return ((RT_F4_API){0., 0.75, 1., 1.});
	return ((RT_F4_API){0.87, 1., 1., 1.});
}

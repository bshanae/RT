/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disruption.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:02:22 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DISRUPTION_H
# define RT_DISRUPTION_H

# include <math.h>

# include "color_list.h"
# include "disruption_perlin_noise.h"
# include "f2.h"

# define DISRUPTION_WIDTH	960
# define DISRUPTION_HEIGHT	960

# define TAU 6.2831853071

typedef	enum		e_disruption_type
{
	checkerboard,
	sine_wave,
	perlin_noise
}					t_disruption_type;

RT_F4_API			disruption_checkerboard(double x, double y);

RT_F4_API			disruption_sine_wave(double x, double y);

RT_F4_API			disruption_perlin_noise(double x, double y);

#endif

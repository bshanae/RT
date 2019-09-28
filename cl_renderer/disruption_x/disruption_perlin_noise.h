/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disruption_perlin_noise.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:02:47 by ashari            #+#    #+#             */
/*   Updated: 2019/09/28 16:02:49 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISRUPTION_PERLIN_NOISE_H
# define DISRUPTION_PERLIN_NOISE_H

# include "rt_cl_include.h"
# include "rt_float.h"

# define FRACT(x) x - floor(x)

double			lerp(double a, double b, double t);

double			quantic_curve(double t);

RT_F2_API		hash(RT_F2_API x);

#endif

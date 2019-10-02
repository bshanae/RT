/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disruption_checkerboard.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:02:28 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "disruption.h"

RT_F4_API			disruption_checkerboard(double x, double y)
{
	double			value;

	value = floor(x * 1.931) + floor(y * 1.931);
	if (fmod(value, 2.) == 0)
		return (COLOR_WHITE);
	return (COLOR_BLACK);
}

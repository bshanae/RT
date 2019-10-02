/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_background_translate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:21:52 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

CHAR_REF			rt_background_translate(t_rt_background i)
{
	if (i == rt_background_none)
		return ("None");
	else if (i == rt_background_one)
		return ("One color");
	else if (i == rt_background_interpolation)
		return ("Interpolated color");
	rt_raise_warning("rt_background : unknown value");
	return (NULL);
}

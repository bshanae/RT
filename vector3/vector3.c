/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:13:34 by ashari            #+#    #+#             */
/*   Updated: 2019/07/02 11:17:32 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

float				vector3_length(const t_vector3 *me)
{
	return (sqrtf(me->x * me->x + me->y * me->y + me->z * me->z));
}

float				vector3_s_length(const t_vector3 me)
{
	return (sqrtf(me.x * me.x + me.y * me.y + me.z * me.z));
}

void				vector3_normalize(t_vector3 *me)
{
	float		length;

	length = vector3_length(me);
	me->x /= length;
	me->y /= length;
	me->z /= length;
}

t_vector3			vector3_s_normalize(t_vector3 me)
{
	float		length;

	length = vector3_length(&me);
	me.x /= length;
	me.y /= length;
	me.z /= length;
	return (me);
}

t_vector3			vector3_normalized(const t_vector3 *me)
{
	t_vector3		result;

	result = *me;
	vector3_normalize(&result);
	return (result);
}

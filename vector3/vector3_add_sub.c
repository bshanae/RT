/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_add_sub.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 20:00:46 by ashari            #+#    #+#             */
/*   Updated: 2019/06/30 20:00:52 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3			vector3_sub(t_vector3 *v1, t_vector3 *v2)
{
	t_vector3		result;

	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return (result);
}

void				vector3_s_sub_eq(t_vector3 *v1, t_vector3 v2)
{
	v1->x -= v2.x;
	v1->y -= v2.y;
	v1->z -= v2.z;
}

void				vector3_add_eq(t_vector3 *v1, const t_vector3 *v2)
{
	v1->x += v2->x;
	v1->y += v2->y;
	v1->z += v2->z;
}

void				vector3_s_add_eq(t_vector3 *v1, t_vector3 v2)
{
	v1->x += v2.x;
	v1->y += v2.y;
	v1->z += v2.z;
}

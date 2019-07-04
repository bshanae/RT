/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_math_operations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:56:06 by ashari            #+#    #+#             */
/*   Updated: 2019/06/30 19:59:07 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector3.h"

t_vector3			vector3_mul(const t_vector3 *v1, float k)
{
	t_vector3		result;

	result.x = v1->x * k;
	result.y = v1->y * k;
	result.z = v1->z * k;
	return (result);
}

t_vector3			vector3_s_mul(t_vector3 v1, float k)
{
	v1.x *= k;
	v1.y *= k;
	v1.z *= k;
	return (v1);
}

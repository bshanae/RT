/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:13:38 by ashari            #+#    #+#             */
/*   Updated: 2019/06/30 19:13:39 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# include <stdarg.h>
# include <math.h>
# include <stdlib.h>

typedef struct		s_vector3
{
	float			x;
	float			y;
	float			z;
}					t_vector3;

float				vector3_length(const t_vector3 *me);

float				vector3_s_length(const t_vector3 me);

void				vector3_normalize(t_vector3 *me);

t_vector3			vector3_normalized(const t_vector3 *me);

t_vector3			vector3_s_normalize(t_vector3 me);

t_vector3			vector3_sub(t_vector3 *v1, t_vector3 *v2);

void				vector3_s_sub_eq(t_vector3 *v1, t_vector3 v2);

void				vector3_add_eq(t_vector3 *v1, const t_vector3 *v2);

void				vector3_s_add_eq(t_vector3 *v1, t_vector3 v2);

t_vector3			vector3_s_mul(t_vector3 v1, float k);

t_vector3			vector3_mul(const t_vector3 *v1, float k);

void				vector3_rotate_x(t_vector3 *me, float theta);

void				vector3_rotate_y(t_vector3 *me, float theta);

#endif

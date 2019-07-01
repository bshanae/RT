/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:10:58 by ashari            #+#    #+#             */
/*   Updated: 2019/07/01 12:05:47 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "vector3.h"

# include <stdarg.h>

typedef enum		e_light_type
{
	light_ambient,
	light_point,
	light_directional
}					t_light_type;

typedef	struct		s_light
{
	t_light_type	type;
	float			intensity;
	t_vector3		vector;
}					t_light;

t_light				light_create(t_light_type type, ...);

void				light_move(t_light *light, t_vector3 step);

#endif

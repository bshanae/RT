/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:10:49 by ashari            #+#    #+#             */
/*   Updated: 2019/07/02 11:17:32 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include "ray.h"
# include "light.h"
# include "material.h"

typedef struct			s_intersection
{
	t_ray				ray;
	t_vector3			normal;
	float				diffuse_intensity;
	float				specular_intensity;
	t_vector3			color;
	const t_material	material;
	float				shadow_ratio;
	int					highlight;
}						t_intersection;

#endif

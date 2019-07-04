/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:13:13 by ashari            #+#    #+#             */
/*   Updated: 2019/07/02 11:17:32 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_LIST_H
# define SHAPE_LIST_H

# include "libft_standart.h"

# include "vector3.h"
# include "shape.h"

/*
********************************************************************************
**						SPHERE
********************************************************************************
*/

typedef struct			s_sphere_data
{
	t_vector3			center;
	float				radius;
}						t_sphere_data;

void					sphere_move(t_shape *shape, t_vector3 move);

t_shape					shape_sphere
	(t_vector3 center, float radius, t_material material);

/*
********************************************************************************
**						PLANE
********************************************************************************
*/

typedef struct			s_plane_data
{
	t_vector3			position;
	t_vector3			normal;
}						t_plane_data;

void					plane_move(t_shape *shape, t_vector3 move);

t_shape					shape_plane
	(t_vector3 position, t_vector3 normal, t_material material);

/*
********************************************************************************
**						CYLINDER
********************************************************************************
*/

typedef struct			s_cylinder_data
{
	t_vector3			top;
	t_vector3			bottom;
	float				radius;
	t_vector3			axis;
}						t_cylinder_data;

void					cylinder_move(t_shape *shape, t_vector3 move);

t_shape					shape_cylinder
	(t_vector3 top, t_vector3 bottom, float radius, t_material material);

/*
********************************************************************************
**						AABB
********************************************************************************
*/

typedef struct			s_aabb_data
{
	t_vector3			min;
	t_vector3			max;
}						t_aabb_data;

void					aabb_move(t_shape *shape, t_vector3 move);

t_shape					shape_aabb
						(t_vector3 min,
						t_vector3 max,
						t_material material);

/*
********************************************************************************
**						CONE
********************************************************************************
*/

typedef struct			s_cone_data
{
	t_vector3			top;
	t_vector3			bottom;
	float				radius;
	float				tangens;
	t_vector3			axis;
}						t_cone_data;

void					cone_move(t_shape *shape, t_vector3 move);

t_shape					shape_cone
	(t_vector3 top, t_vector3 bottom, float tangens, t_material material);

/*
********************************************************************************
**						MOVE
********************************************************************************
*/

void					shape_move(t_shape *shape, t_vector3 step);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_definition.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:54:42 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_DEFINITION_H
# define OBJECT_DEFINITION_H

# include "rt_parameters.h"
# include "material.h"

typedef enum		e_object_type
{
	object_type_light_ambient,
	object_type_light_point,
	object_type_light_direct,
	object_type_sphere,
	object_type_plane,
	object_type_cone,
	object_type_cylinder,
	object_type_box,
	object_type_paraboloid,
	object_type_moebius,
	object_type_limited,
	object_type_torus,
	object_type_mandelbulb,
	object_type_julia,
	object_type_perforated_cube,
	object_type_explosion,
	object_type_csg,
	object_type_end
}					t_object_type;

typedef enum		e_object_flag
{
	object_flag_rt_only,
	object_flag_rm_only,
	object_flag_universal
}					t_object_flag;

typedef struct		s_object
{
	char			name[RT_NAME_SIZE];
	int				id;
	t_object_type	type;
	int				texture_id;
	t_material		material;
	char			data[RT_OBJECT_CAPACITY];
	int				is_visible;
	int				is_selected;
}					t_object;

const char			*object_translate(t_object_type type);

#endif

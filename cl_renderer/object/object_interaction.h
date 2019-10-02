/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_interaction.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:55:02 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_INTERACTION_H
# define OBJECT_INTERACTION_H

# include "rt_float.h"

# include "error_framework.h"
# include "f4.h"
# include "object_definition.h"
# include "object_x.h"
# include "material_list.h"
# include "object_flag.h"

# include <stdarg.h>

u_int				object_flag_get(t_object *object);

void				object_build(t_object *space, t_object_type type, ...);

void				object_light_ambient_build(t_object *space, va_list *args);
void				object_light_point_build(t_object *space, va_list *args);
void				object_light_direct_build(t_object *space, va_list *args);
void				object_sphere_build(t_object *space, va_list *args);
void				object_plane_build(t_object *space, va_list *args);
void				object_cone_build(t_object *space, va_list *args);
void				object_cylinder_build(t_object *space, va_list *args);
void				object_box_build(t_object *space, va_list *args);
void				object_paraboloid_build(t_object *space, va_list *args);
void				object_moebius_build(t_object *space, va_list *args);
void				object_limited_build(t_object *space, va_list *args);
void				object_torus_build(t_object *space, va_list *args);
void				object_mandelbulb_build(t_object *space, va_list *args);
void				object_julia_build(t_object *space, va_list *args);
void				object_perforated_cube_build(
					t_object *space, va_list *args);
void				object_explosion_build(t_object *space, va_list *args);
void				object_csg_build(t_object *space, va_list *args);

#endif

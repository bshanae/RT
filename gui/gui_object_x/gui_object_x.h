/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_x.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:40:58 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_OBJECT_X_H
# define GUI_OBJECT_X_H

# include "rt_float.h"

# include "libft_standart.h"
# include "error_framework.h"
# include "gui_entry.h"
# include "f4.h"
# include "object_definition.h"
# include "object_x.h"
# include "gui_scene_common.h"

# include <gtk/gtk.h>

/*
********************************************************************************
**							LIGHT_POINT
********************************************************************************
*/

typedef struct				s_gui_init_light_point
{
	char					position_x[64];
	char					position_y[64];
	char					position_z[64];
}							t_gui_init_light_point;

typedef struct				s_gui_object_light_point
{
	GtkEntry				*position_x;
	GtkEntry				*position_y;
	GtkEntry				*position_z;
}							t_gui_object_light_point;

t_gui_object_light_point	gui_object_light_point_init
							(t_gui_init_light_point *init, GtkBuilder *builder);
void						gui_object_light_point_get
							(t_gui_object_light_point *gui, t_object *object);
void						gui_object_light_point_set
							(t_gui_object_light_point *gui, t_object *object);
void						gui_object_light_point_clear
							(t_gui_object_light_point *gui);

/*
********************************************************************************
**							LIGHT_DIRECT
********************************************************************************
*/

typedef struct				s_gui_init_light_direct
{
	char					direction_x[64];
	char					direction_y[64];
	char					direction_z[64];
}							t_gui_init_light_direct;

typedef struct				s_gui_object_light_direct
{
	GtkEntry				*direction_x;
	GtkEntry				*direction_y;
	GtkEntry				*direction_z;
}							t_gui_object_light_direct;

t_gui_object_light_direct	gui_object_light_direct_init
							(t_gui_init_light_direct *i, GtkBuilder *builder);
void						gui_object_light_direct_get
							(t_gui_object_light_direct *gui, t_object *object);
void						gui_object_light_direct_set
							(t_gui_object_light_direct *gui, t_object *object);
void						gui_object_light_direct_clear
							(t_gui_object_light_direct *gui);

/*
********************************************************************************
**							SPHERE
********************************************************************************
*/

typedef struct				s_gui_init_sphere
{
	char					position_x[64];
	char					position_y[64];
	char					position_z[64];
	char					radius[64];
}							t_gui_init_sphere;

typedef struct				s_gui_object_sphere
{
	GtkEntry				*position_x;
	GtkEntry				*position_y;
	GtkEntry				*position_z;
	GtkEntry				*radius;
}							t_gui_object_sphere;

t_gui_object_sphere			gui_object_sphere_init
							(t_gui_init_sphere *init, GtkBuilder *builder);
void						gui_object_sphere_get
							(t_gui_object_sphere *gui, t_object *object);
void						gui_object_sphere_set
							(t_gui_object_sphere *gui, t_object *object);
void						gui_object_sphere_clear(t_gui_object_sphere *gui);

/*
********************************************************************************
**							PLANE
********************************************************************************
*/

typedef struct				s_gui_init_plane
{
	char					position_x[64];
	char					position_y[64];
	char					position_z[64];
	char					normal_x[64];
	char					normal_y[64];
	char					normal_z[64];
}							t_gui_init_plane;

typedef struct				s_gui_object_plane
{
	GtkEntry				*position_x;
	GtkEntry				*position_y;
	GtkEntry				*position_z;
	GtkEntry				*normal_x;
	GtkEntry				*normal_y;
	GtkEntry				*normal_z;
}							t_gui_object_plane;

t_gui_object_plane			gui_object_plane_init
							(t_gui_init_plane *init, GtkBuilder *builder);
void						gui_object_plane_get
							(t_gui_object_plane *gui, t_object *object);
void						gui_object_plane_set
							(t_gui_object_plane *gui, t_object *object);
void						gui_object_plane_clear
							(t_gui_object_plane *gui);

/*
********************************************************************************
**							CONE
********************************************************************************
*/

typedef struct				s_gui_init_cone
{
	char					top_x[64];
	char					top_y[64];
	char					top_z[64];
	char					bottom_x[64];
	char					bottom_y[64];
	char					bottom_z[64];
	char					radius[64];
}							t_gui_init_cone;

typedef struct				s_gui_object_cone
{
	GtkBox					*box;
	GtkEntry				*top_x;
	GtkEntry				*top_y;
	GtkEntry				*top_z;
	GtkEntry				*bottom_x;
	GtkEntry				*bottom_y;
	GtkEntry				*bottom_z;
	GtkEntry				*radius;
}							t_gui_object_cone;

t_gui_object_cone			gui_object_cone_init
							(t_gui_init_cone *init, GtkBuilder *builder);
void						gui_object_cone_get
							(t_gui_object_cone *gui, t_object *object);
void						gui_object_cone_set
							(t_gui_object_cone *gui, t_object *object);
void						gui_object_cone_clear
							(t_gui_object_cone *gui);

/*
********************************************************************************
**							CYLINDER
********************************************************************************
*/

typedef struct				s_gui_init_cylinder
{
	char					top_x[64];
	char					top_y[64];
	char					top_z[64];
	char					bottom_x[64];
	char					bottom_y[64];
	char					bottom_z[64];
	char					radius[64];
}							t_gui_init_cylinder;

typedef struct				s_gui_object_cylinder
{
	GtkEntry				*top_x;
	GtkEntry				*top_y;
	GtkEntry				*top_z;
	GtkEntry				*bottom_x;
	GtkEntry				*bottom_y;
	GtkEntry				*bottom_z;
	GtkEntry				*radius;
}							t_gui_object_cylinder;

t_gui_object_cylinder		gui_object_cylinder_init
							(t_gui_init_cylinder *init, GtkBuilder *builder);
void						gui_object_cylinder_get
							(t_gui_object_cylinder *gui, t_object *object);
void						gui_object_cylinder_set
							(t_gui_object_cylinder *gui, t_object *object);
void						gui_object_cylinder_clear
							(t_gui_object_cylinder *gui);

/*
********************************************************************************
**							BOX
********************************************************************************
*/

typedef struct				s_gui_init_box
{
	char					position_x[64];
	char					position_y[64];
	char					position_z[64];
	char					size_x[64];
	char					size_y[64];
	char					size_z[64];
}							t_gui_init_box;

typedef struct				s_gui_object_box
{
	GtkEntry				*position_x;
	GtkEntry				*position_y;
	GtkEntry				*position_z;
	GtkEntry				*size_x;
	GtkEntry				*size_y;
	GtkEntry				*size_z;
}							t_gui_object_box;

t_gui_object_box			gui_object_box_init
							(t_gui_init_box *init, GtkBuilder *builder);
void						gui_object_box_get
							(t_gui_object_box *gui, t_object *object);
void						gui_object_box_set
							(t_gui_object_box *gui, t_object *object);
void						gui_object_box_clear
							(t_gui_object_box *gui);

/*
********************************************************************************
**							PARABOLOID
********************************************************************************
*/

typedef struct				s_gui_init_paraboloid
{
	char					extremum_x[64];
	char					extremum_y[64];
	char					extremum_z[64];
	char					axis_x[64];
	char					axis_y[64];
	char					axis_z[64];
	char					radius[64];
}							t_gui_init_paraboloid;

typedef struct				s_gui_object_paraboloid
{
	GtkEntry				*extremum_x;
	GtkEntry				*extremum_y;
	GtkEntry				*extremum_z;
	GtkEntry				*axis_x;
	GtkEntry				*axis_y;
	GtkEntry				*axis_z;
	GtkEntry				*radius;
}							t_gui_object_paraboloid;

t_gui_object_paraboloid		gui_object_paraboloid_init
							(t_gui_init_paraboloid *init, GtkBuilder *builder);
void						gui_object_paraboloid_get
							(t_gui_object_paraboloid *gui, t_object *object);
void						gui_object_paraboloid_set
							(t_gui_object_paraboloid *gui, t_object *object);
void						gui_object_paraboloid_clear
							(t_gui_object_paraboloid *gui);

/*
********************************************************************************
**							MOEBIUS
********************************************************************************
*/

typedef struct				s_gui_init_moebius
{
	char					position_x[64];
	char					position_y[64];
	char					position_z[64];
	char					radius[64];
	char					width[64];
}							t_gui_init_moebius;

typedef struct				s_gui_object_moebius
{
	GtkEntry				*position_x;
	GtkEntry				*position_y;
	GtkEntry				*position_z;
	GtkEntry				*radius;
	GtkEntry				*width;
}							t_gui_object_moebius;

t_gui_object_moebius		gui_object_moebius_init
							(t_gui_init_moebius *init, GtkBuilder *builder);
void						gui_object_moebius_get
							(t_gui_object_moebius *gui, t_object *object);
void						gui_object_moebius_set
							(t_gui_object_moebius *gui, t_object *object);
void						gui_object_moebius_clear
							(t_gui_object_moebius *gui);

/*
********************************************************************************
**							TORUS
********************************************************************************
*/

typedef struct				s_gui_init_torus
{
	char					position_x[64];
	char					position_y[64];
	char					position_z[64];
	char					width[64];
	char					radius[64];
}							t_gui_init_torus;

typedef struct				s_gui_object_torus
{
	GtkEntry				*position_x;
	GtkEntry				*position_y;
	GtkEntry				*position_z;
	GtkEntry				*width;
	GtkEntry				*radius;
}							t_gui_object_torus;

t_gui_object_torus			gui_object_torus_init
							(t_gui_init_torus *init, GtkBuilder *builder);
void						gui_object_torus_get
							(t_gui_object_torus *gui, t_object *object);
void						gui_object_torus_set
							(t_gui_object_torus *gui, t_object *object);
void						gui_object_torus_clear
							(t_gui_object_torus *gui);

/*
********************************************************************************
**							MANDELBULB
********************************************************************************
*/

typedef struct				s_gui_init_mandelbulb
{
	char					iterations[64];
	char					power[64];
}							t_gui_init_mandelbulb;

typedef struct				s_gui_object_mandelbulb
{
	GtkEntry				*iterations;
	GtkEntry				*power;
}							t_gui_object_mandelbulb;

t_gui_object_mandelbulb		gui_object_mandelbulb_init
							(t_gui_init_mandelbulb *init, GtkBuilder *builder);
void						gui_object_mandelbulb_get
							(t_gui_object_mandelbulb *gui, t_object *object);
void						gui_object_mandelbulb_set
							(t_gui_object_mandelbulb *gui, t_object *object);
void						gui_object_mandelbulb_clear
							(t_gui_object_mandelbulb *gui);

/*
********************************************************************************
**							JULIA
********************************************************************************
*/

typedef struct				s_gui_init_julia
{
	char					iterations[64];
	char					value_x[64];
	char					value_y[64];
	char					value_z[64];
	char					value_w[64];
}							t_gui_init_julia;

typedef struct				s_gui_object_julia
{
	GtkEntry				*iterations;
	GtkEntry				*value_x;
	GtkEntry				*value_y;
	GtkEntry				*value_z;
	GtkEntry				*value_w;
}							t_gui_object_julia;

t_gui_object_julia			gui_object_julia_init
							(t_gui_init_julia *init, GtkBuilder *builder);
void						gui_object_julia_get
							(t_gui_object_julia *gui, t_object *object);
void						gui_object_julia_set
							(t_gui_object_julia *gui, t_object *object);
void						gui_object_julia_clear
							(t_gui_object_julia *gui);

/*
********************************************************************************
**							P_CUBE
********************************************************************************
*/

typedef struct				s_gui_init_p_cube
{
	char					position_x[64];
	char					position_y[64];
	char					position_z[64];
	char					iterations[64];
}							t_gui_init_p_cube;

typedef struct				s_gui_object_p_cube
{
	GtkEntry				*position_x;
	GtkEntry				*position_y;
	GtkEntry				*position_z;
	GtkEntry				*iterations;
}							t_gui_object_p_cube;

t_gui_object_p_cube			gui_object_p_cube_init
							(t_gui_init_p_cube *init, GtkBuilder *builder);
void						gui_object_p_cube_get
							(t_gui_object_p_cube *gui, t_object *object);
void						gui_object_p_cube_set
							(t_gui_object_p_cube *gui, t_object *object);
void						gui_object_p_cube_clear
							(t_gui_object_p_cube *gui);

/*
********************************************************************************
**							EXPLOSION
********************************************************************************
*/

typedef struct				s_gui_init_explosion
{
	char					position_x[64];
	char					position_y[64];
	char					position_z[64];
	char					radius[64];
	char					noise[64];
}							t_gui_init_explosion;

typedef struct				s_gui_object_explosion
{
	GtkEntry				*position_x;
	GtkEntry				*position_y;
	GtkEntry				*position_z;
	GtkEntry				*radius;
	GtkEntry				*noise;
}							t_gui_object_explosion;

t_gui_object_explosion		gui_object_explosion_init
							(t_gui_init_explosion *init, GtkBuilder *builder);
void						gui_object_explosion_get
							(t_gui_object_explosion *gui, t_object *object);
void						gui_object_explosion_set
							(t_gui_object_explosion *gui, t_object *object);
void						gui_object_explosion_clear
							(t_gui_object_explosion *gui);

/*
********************************************************************************
**							PAIR
********************************************************************************
*/

typedef struct				s_gui_init_pair
{
	char					first_combo[64];
	char					first_list[64];
	char					second_combo[64];
	char					second_list[64];
}							t_gui_init_pair;

typedef struct				s_gui_object_pair
{
	GtkComboBox				*first_combo;
	GtkListStore			*first_list;
	GtkComboBox				*second_combo;
	GtkListStore			*second_list;
}							t_gui_object_pair;

t_gui_object_pair			gui_object_pair_init
							(t_gui_init_pair *init, GtkBuilder *builder);
void						gui_object_pair_get
							(t_gui_object_pair*gui, t_object *object);
void						gui_object_pair_set
							(t_gui_object_pair *gui, t_object *object);
void						gui_object_pair_clear(t_gui_object_pair *gui);

#endif

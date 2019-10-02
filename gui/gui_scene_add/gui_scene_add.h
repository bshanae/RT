/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_add.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:16:44 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:17:59 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_SCENE_ADD_H
# define GUI_SCENE_ADD_H

# include "rt_parameters.h"

# include "libft_standart.h"
# include "error_framework.h"
# include "gui_material.h"
# include "gui_object_x.h"
# include "gui_scene_common.h"
# include "object_definition.h"
# include "color_list.h"

# include <gtk/gtk.h>

typedef struct					s_gui_scene_add
{
	t_gui_scene_common			*common;
	GtkDialog					*dialog;
	GtkEntry					*name;
	GtkComboBox					*type_combo;
	t_gui_object_light_point	light_point;
	t_gui_object_light_direct	light_direct;
	t_gui_object_sphere			sphere;
	t_gui_object_plane			plane;
	t_gui_object_cone			cone;
	t_gui_object_cylinder		cylinder;
	t_gui_object_box			box;
	t_gui_object_paraboloid		paraboloid;
	t_gui_object_moebius		moebius;
	t_gui_object_pair			limited;
	t_gui_object_torus			torus;
	t_gui_object_mandelbulb		mandelbulb;
	t_gui_object_julia			julia;
	t_gui_object_p_cube			p_cube;
	t_gui_object_explosion		explosion;
	t_gui_object_pair			csg;
	t_gui_material				material;
	t_object					temp_object;
	GtkStack					*stack;
	t_object_type				current_type;
	int							generator_next_id;
}								t_gui_scene_add;

t_gui_scene_add					*gui_scene_add_new(GtkBuilder *builder);
void							gui_scene_add_delete(t_gui_scene_add **object);

void							gui_scene_add_init_own
								(t_gui_scene_add *add, GtkBuilder *builder);
void							gui_scene_add_init_light_point
								(t_gui_scene_add *add, GtkBuilder *builder);
void							gui_scene_add_init_light_direct
								(t_gui_scene_add *add, GtkBuilder *builder);
void							gui_scene_add_init_sphere
								(t_gui_scene_add *add, GtkBuilder *builder);
void							gui_scene_add_init_plane
								(t_gui_scene_add *add, GtkBuilder *builder);
void							gui_scene_add_init_cone
								(t_gui_scene_add *add, GtkBuilder *builder);
void							gui_scene_add_init_cylinder
								(t_gui_scene_add *add, GtkBuilder *builder);
void							gui_scene_add_init_box
								(t_gui_scene_add *add, GtkBuilder *builder);
void							gui_scene_add_init_paraboloid
								(t_gui_scene_add *add, GtkBuilder *builder);
void							gui_scene_add_init_moebius
								(t_gui_scene_add *add, GtkBuilder *builder);
void							gui_scene_add_init_limited
								(t_gui_scene_add *add, GtkBuilder *builder);
void							gui_scene_add_init_torus
								(t_gui_scene_add *add, GtkBuilder *builder);
void							gui_scene_add_init_mandelbulb
								(t_gui_scene_add *add, GtkBuilder *builder);
void							gui_scene_add_init_julia
								(t_gui_scene_add *add, GtkBuilder *builder);
void							gui_scene_add_init_p_cube
								(t_gui_scene_add *add, GtkBuilder *builder);
void							gui_scene_add_init_explosion
								(t_gui_scene_add *add, GtkBuilder *builder);
void							gui_scene_add_init_csg
								(t_gui_scene_add *add, GtkBuilder *builder);
void							gui_scene_add_init_material
								(t_gui_scene_add *add, GtkBuilder *builder);

char							*gui_scene_add_gen_name
								(t_gui_scene_add *add);
void							gui_scene_add_prepare(t_gui_scene_add *add);
void							gui_scene_add_build_object
								(t_gui_scene_add *add, t_object *space);

#endif

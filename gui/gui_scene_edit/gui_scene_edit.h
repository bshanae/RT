/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_edit.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:49:01 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_SCENE_EDIT_H
# define GUI_SCENE_EDIT_H

# include "rt_float.h"

# include "gui_object_x.h"
# include "gui_material.h"
# include "gui_control.h"
# include "gui_scene_common.h"
# include "scene.h"

# include <gtk/gtk.h>

typedef struct					s_gui_scene_edit
{
	t_gui_scene_common			*common;
	GtkComboBox					*background_combo;
	GtkStack					*stack;
	GtkBox						*info;
	GtkTreeSelection			*selection;
	t_rt_bool					selection_silent;
	int							current_id;
	GtkTreeIter					iter;
	GtkWidget					*remove_button;
	GtkDialog					*remove_dialog;
	GtkEntry					*name;
	GtkEntry					*type;
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
	t_gui_control				control;
}								t_gui_scene_edit;

t_gui_scene_edit				*gui_scene_edit_new
								(GtkBuilder *builder);
void							gui_scene_edit_delete
								(t_gui_scene_edit **object);

void							gui_scene_edit_init_own
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void							gui_scene_edit_init_light_point
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void							gui_scene_edit_init_light_direct
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void							gui_scene_edit_init_sphere
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void							gui_scene_edit_init_plane
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void							gui_scene_edit_init_cone
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void							gui_scene_edit_init_cylinder
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void							gui_scene_edit_init_box
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void							gui_scene_edit_init_paraboloid
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void							gui_scene_edit_init_moebius
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void							gui_scene_edit_init_limited
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void							gui_scene_edit_init_torus
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void							gui_scene_edit_init_mandelbulb
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void							gui_scene_edit_init_julia
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void							gui_scene_edit_init_p_cube
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void							gui_scene_edit_init_explosion
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void							gui_scene_edit_init_csg
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void							gui_scene_edit_init_material
								(t_gui_scene_edit *edit, GtkBuilder *builder);

void							gui_scene_edit_background_get
								(t_gui_scene_edit *edit, t_scene *scene);
int								gui_scene_edit_background_read_value
								(t_gui_scene_edit *edit);

void							gui_scene_edit_show
								(t_gui_scene_edit *edit, t_object *object);
void							gui_scene_edit_apply
								(t_gui_scene_edit *edit, t_scene *scene);
void							gui_scene_edit_select
								(t_gui_scene_edit *edit, t_scene *scene);
void							gui_scene_edit_unselect(t_gui_scene_edit *edit);

#endif

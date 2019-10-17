/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_material.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:39:27 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_MATERIAL_H
# define GUI_MATERIAL_H

# include "rt_parameters.h"

# include "gui_entry.h"
# include "gui_color.h"
# include "material.h"
# include "material_list.h"
# include "gui_scene_common.h"

# include <gtk/gtk.h>

typedef enum			e_gui_material_mod
{
	gui_material_material,
	gui_material_texture
}						t_gui_material_mod;

typedef struct			s_gui_init_material
{
	char				switcher_stack[64];
	char				switcher_material[64];
	char				switcher_texture[64];
	char				stack[64];
	char				color_r[64];
	char				color_g[64];
	char				color_b[64];
	char				color_button[64];
	char				color_box[64];
	char				emission_r[64];
	char				emission_g[64];
	char				emission_b[64];
	char				emission_button[64];
	char				emission_box[64];
	char				reflectance_adjustment[64];
	char				reflectance_scale[64];
	char				reflectance_label[64];
	char				transparency_adjustment[64];
	char				transparency_scale[64];
	char				transparency_label[64];
	char				texture_combo[64];
	char				texture_list[64];
}						t_gui_init_material;

typedef struct			s_gui_material
{
	GtkStack			*switcher_stack;
	GtkToggleButton		*switcher_material;
	GtkToggleButton		*switcher_texture;
	t_rt_bool			switcher_block;
	t_rt_state			texture_state;
	t_gui_material_mod	current_mod;
	GtkStack			*stack;
	GtkEntry			*color_r;
	GtkEntry			*color_g;
	GtkEntry			*color_b;
	GtkColorButton		*color_button;
	GtkWidget			*color_box;
	int					color_silent;
	GtkEntry			*emission_r;
	GtkEntry			*emission_g;
	GtkEntry			*emission_b;
	GtkColorButton		*emission_button;
	GtkWidget			*emission_box;
	GtkAdjustment		*reflectance_adjustment;
	GtkScale			*reflectance_scale;
	GtkLabel			*reflectance_label;
	GtkAdjustment		*transparency_adjustment;
	GtkScale			*transparency_scale;
	GtkLabel			*transparency_label;
	GtkComboBox			*texture_combo;
	GtkListStore		*texture_list;
}						t_gui_material;

t_gui_material			gui_material_init
						(const t_gui_init_material *init, GtkBuilder *builder);

void					gui_material_get
						(t_gui_material *gui,
						t_material *material, int *texture);
void					gui_material_set
						(t_gui_material *gui,
						t_material *material, int *texture);

void					gui_material_texture_get
						(t_gui_material *material, int id);
void					gui_material_texture_set
						(t_gui_material *material, int *id);

void					gui_material_hide(t_gui_material *material);
void					gui_material_prepare
						(t_gui_material *material, t_object *object);

void					gui_material_color_enable(t_gui_material *material);
void					gui_material_color_disable(t_gui_material *material);

void					gui_material_emission_enable(t_gui_material *material);
void					gui_material_emission_disable(t_gui_material *material);

void					gui_material_texture_enable(t_gui_material *material);
void					gui_material_texture_disable(t_gui_material *material);

void					gui_material_special_disable(t_gui_material *material);
void					gui_material_special_enable(t_gui_material *material);

void					gui_material_switch_mod
						(t_gui_material *material, t_gui_material_mod mod);

#endif

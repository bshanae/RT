/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_material_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:47:18 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_material.h"

static void			static_init_a
	(t_gui_material *material, const t_gui_init_material *init,
	GtkBuilder *builder)
{
	material->switcher_stack = RT_GUI_GET(builder, init->switcher_stack);
	material->switcher_material = RT_GUI_GET(builder, init->switcher_material);
	material->switcher_texture = RT_GUI_GET(builder, init->switcher_texture);
	material->switcher_block = rt_false;
	material->stack = RT_GUI_GET(builder, init->stack);
	material->color_r = RT_GUI_GET(builder, init->color_r);
	material->color_g = RT_GUI_GET(builder, init->color_g);
	material->color_b = RT_GUI_GET(builder, init->color_b);
	material->color_button = RT_GUI_GET(builder, init->color_button);
	material->color_box = RT_GUI_GET(builder, init->color_box);
	material->color_silent = 0;
	material->emission_r = RT_GUI_GET(builder, init->emission_r);
	material->emission_g = RT_GUI_GET(builder, init->emission_g);
	material->emission_b = RT_GUI_GET(builder, init->emission_b);
	material->emission_button = RT_GUI_GET(builder, init->emission_button);
	material->emission_box = RT_GUI_GET(builder, init->emission_box);
	material->texture_combo = RT_GUI_GET(builder, init->texture_combo);
	material->texture_list = RT_GUI_GET(builder, init->texture_list);
	material->texture_state = rt_off;
}

static void			static_init_b
	(t_gui_material *material, const t_gui_init_material *init,
	GtkBuilder *builder)
{
	material->reflectance_adjustment =
		RT_GUI_GET(builder, init->reflectance_adjustment);
	material->reflectance_scale =
		RT_GUI_GET(builder, init->reflectance_scale);
	material->reflectance_label =
		RT_GUI_GET(builder, init->reflectance_label);
	material->transparency_adjustment =
		RT_GUI_GET(builder, init->transparency_adjustment);
	material->transparency_scale =
		RT_GUI_GET(builder, init->transparency_scale);
	material->transparency_label =
		RT_GUI_GET(builder, init->transparency_label);
}

t_gui_material		gui_material_init
	(const t_gui_init_material *init, GtkBuilder *builder)
{
	t_gui_material	material;

	static_init_a(&material, init, builder);
	static_init_b(&material, init, builder);
	gui_material_switch_mod(&material, gui_material_material);
	return (material);
}

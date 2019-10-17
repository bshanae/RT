/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_add_init_material.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:30:39 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_add.h"

static void				static_init_a(t_gui_init_material *init)
{
	ft_strcpy(init->switcher_stack, "scene_add_material_switcher_stack");
	ft_strcpy(init->switcher_material, "scene_add_material_switcher_material");
	ft_strcpy(init->switcher_texture, "scene_add_material_switcher_texture");
	ft_strcpy(init->stack, "scene_add_material_stack");
	ft_strcpy(init->color_r, "scene_add_material_color_r");
	ft_strcpy(init->color_g, "scene_add_material_color_g");
	ft_strcpy(init->color_b, "scene_add_material_color_b");
	ft_strcpy(init->color_button, "scene_add_material_color_button");
	ft_strcpy(init->color_box, "scene_add_material_color_box");
	ft_strcpy(init->emission_r, "scene_add_material_emission_r");
	ft_strcpy(init->emission_g, "scene_add_material_emission_g");
	ft_strcpy(init->emission_b, "scene_add_material_emission_b");
	ft_strcpy(init->emission_button, "scene_add_material_emission_button");
	ft_strcpy(init->emission_box, "scene_add_material_emission_box");
	ft_strcpy(init->texture_combo, "scene_add_material_texture_combo");
	ft_strcpy(init->texture_list, "scene_texture_list");
}

static void				static_init_b(t_gui_init_material *init)
{
	ft_strcpy(init->reflectance_adjustment,
		"scene_add_material_reflectance_adjustment");
	ft_strcpy(init->reflectance_scale, "scene_add_material_reflectance_scale");
	ft_strcpy(init->reflectance_label, "scene_add_material_reflectance_label");
	ft_strcpy(init->transparency_adjustment,
		"scene_add_material_transparency_adjustment");
	ft_strcpy(init->transparency_scale,
		"scene_add_material_transparency_scale");
	ft_strcpy(init->transparency_label,
		"scene_add_material_transparency_label");
}

void					gui_scene_add_init_material
	(t_gui_scene_add *add, GtkBuilder *builder)
{
	t_gui_init_material	init;

	static_init_a(&init);
	static_init_b(&init);
	add->material = gui_material_init(&init, builder);
}

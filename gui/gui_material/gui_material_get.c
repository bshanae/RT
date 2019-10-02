/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_material_get.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:41:28 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:41:51 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_material.h"

void				gui_material_get
	(t_gui_material *gui, t_material *material, int *texture)
{
	t_gui_color		color;
	t_gui_color		emission;

	if (gui->current_mod == gui_material_texture)
		gui_material_texture_get(gui, *texture);
	else
	{
		color = gui_color_from_f4(&material->color);
		emission = gui_color_from_f4(&material->emission);
		gtk_color_button_set_rgba(gui->color_button, &color);
		gui_entry_set_f(gui->color_r, color.red);
		gui_entry_set_f(gui->color_g, color.green);
		gui_entry_set_f(gui->color_b, color.blue);
		gtk_color_button_set_rgba(gui->emission_button, &emission);
		gui_entry_set_f(gui->emission_r, emission.red);
		gui_entry_set_f(gui->emission_g, emission.green);
		gui_entry_set_f(gui->emission_b, emission.blue);
		gtk_adjustment_set_value(gui->reflectance_adjustment,
			material->reflectance);
		gtk_adjustment_set_value(gui->transparency_adjustment,
			material->transparency);
	}
}

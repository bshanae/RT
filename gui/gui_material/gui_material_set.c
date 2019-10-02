/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_material_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:48:31 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:48:35 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_material.h"

static RT_F			static_bound(RT_F value)
{
	if (value < (RT_F)0.)
		return ((RT_F)0.);
	if (value > (RT_F)1.)
		return (RT_F)1.;
	return (value);
}

void				gui_material_set
	(t_gui_material *gui, t_material *material, int *texture)
{
	if (gui->current_mod == gui_material_texture)
		gui_material_texture_set(gui, texture);
	else
	{
		material->color.x = static_bound(gui_entry_get_f(gui->color_r));
		material->color.y = static_bound(gui_entry_get_f(gui->color_g));
		material->color.z = static_bound(gui_entry_get_f(gui->color_b));
		material->color.w = 1.;
		material->emission.x = static_bound(gui_entry_get_f(gui->emission_r));
		material->emission.y = static_bound(gui_entry_get_f(gui->emission_g));
		material->emission.z = static_bound(gui_entry_get_f(gui->emission_b));
		material->emission.w = 1.;
		material->reflectance =
			gtk_adjustment_get_value(gui->reflectance_adjustment);
		material->transparency =
			gtk_adjustment_get_value(gui->transparency_adjustment);
		*texture = -1;
	}
}

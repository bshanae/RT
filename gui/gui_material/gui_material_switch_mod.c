/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_material_switch_mod.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:49:12 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:49:13 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_material.h"

void				gui_material_switch_mod
	(t_gui_material *material, t_gui_material_mod mod)
{
	material->current_mod = mod;
	material->switcher_block = rt_true;
	if (mod == gui_material_material)
	{
		gtk_stack_set_visible_child_name(material->stack, "material");
		gtk_toggle_button_set_active(material->switcher_material, TRUE);
		gtk_toggle_button_set_active(material->switcher_texture, FALSE);
	}
	else if (mod == gui_material_texture)
	{
		gtk_stack_set_visible_child_name(material->stack, "texture");
		gtk_toggle_button_set_active(material->switcher_material, FALSE);
		gtk_toggle_button_set_active(material->switcher_texture, TRUE);
	}
	else
		rt_raise_warning("GUI Material : Unknown mod");
	material->switcher_block = rt_false;
}

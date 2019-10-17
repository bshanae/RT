/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_material_prepare.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:48:07 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_material.h"

static void			static_helper(t_gui_material *material, t_object *object)
{
	if (object_flag_get(object) & RT_OBJECT_HAS_NO_MATERIAL)
	{
		gui_material_color_disable(material);
		gui_material_emission_disable(material);
		gui_material_special_disable(material);
	}
	else if (object_flag_get(object) & RT_OBJECT_LIGHT)
	{
		gui_material_color_disable(material);
		gui_material_emission_enable(material);
		gui_material_special_disable(material);
	}
	else
	{
		gui_material_color_enable(material);
		gui_material_emission_enable(material);
		gui_material_special_enable(material);
	}
}

void				gui_material_prepare
	(t_gui_material *material, t_object *object)
{
	UINT			flag;

	if (object_flag_get(object) & RT_OBJECT_HAS_TEXTURE)
		gui_material_texture_enable(material);
	else
		gui_material_texture_disable(material);
	gui_material_switch_mod(material, object->texture_id == -1 ?
		gui_material_material : gui_material_texture);
	flag = !(object_flag_get(object) & RT_OBJECT_PAIR);
	gtk_widget_set_sensitive(GTK_WIDGET(material->switcher_stack), flag);
	gtk_widget_set_sensitive(GTK_WIDGET(material->stack), flag);
	static_helper(material, object);
}

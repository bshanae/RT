/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_scene_edit_switch_x.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:58:44 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_x.h"

void				gui_signal_scene_edit_switch_material
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	t_gui_material	*material;
	gboolean		state;
	t_object		*object;

	gui = (t_gui *)ptr;
	material = &gui->scene->edit->material;
	if (material->switcher_block == rt_true)
		return ;
	if (gui->scene->edit->material.texture_state == rt_off)
	{
		rt_raise_warning("GUI Editor : Unexpected material stack state");
		return ;
	}
	state = gtk_toggle_button_get_active(material->switcher_material);
	material->switcher_block = rt_true;
	gtk_toggle_button_set_active(material->switcher_texture, !state);
	material->switcher_block = rt_false;
	gui_material_switch_mod(&gui->scene->edit->material, state ?
		gui_material_material : gui_material_texture);
	object = gui->renderer->data.scene->objects + gui->scene->edit->current_id;
	gui_material_get(material, &object->material, &object->texture_id);
	gui_control_show(&gui->scene->edit->control);
}

void				gui_signal_scene_edit_switch_texture
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	t_gui_material	*material;
	gboolean		state;
	t_object		*object;

	gui = (t_gui *)ptr;
	material = &gui->scene->edit->material;
	if (material->switcher_block == rt_true)
		return ;
	if (gui->scene->edit->material.texture_state == rt_off)
	{
		rt_raise_warning("GUI Editor : Unexpected material stack state");
		return ;
	}
	state = gtk_toggle_button_get_active(material->switcher_texture);
	material->switcher_block = rt_true;
	gtk_toggle_button_set_active(material->switcher_material, !state);
	material->switcher_block = rt_false;
	gui_material_switch_mod(&gui->scene->edit->material, state ?
		gui_material_texture : gui_material_material);
	object = gui->renderer->data.scene->objects + gui->scene->edit->current_id;
	gui_material_get(material, &object->material, &object->texture_id);
	gui_control_show(&gui->scene->edit->control);
}

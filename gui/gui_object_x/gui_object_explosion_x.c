/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_explosion_x.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:29:01 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x.h"

t_gui_object_explosion		gui_object_explosion_init
	(t_gui_init_explosion *init, GtkBuilder *builder)
{
	t_gui_object_explosion	explosion;

	explosion.position_x = RT_GUI_GET(builder, init->position_x);
	explosion.position_y = RT_GUI_GET(builder, init->position_y);
	explosion.position_z = RT_GUI_GET(builder, init->position_z);
	explosion.radius = RT_GUI_GET(builder, init->radius);
	explosion.noise = RT_GUI_GET(builder, init->noise);
	return (explosion);
}

void						gui_object_explosion_get
	(t_gui_object_explosion *gui, t_object *object)
{
	t_object_explosion		*data;

	data = (t_object_explosion *)object->data;
	gui_entry_set_f(gui->position_x, data->position.x);
	gui_entry_set_f(gui->position_y, data->position.y);
	gui_entry_set_f(gui->position_z, data->position.z);
	gui_entry_set_f(gui->radius, data->radius);
	gui_entry_set_f(gui->noise, data->noise_amplitude);
}

void						gui_object_explosion_set
	(t_gui_object_explosion *gui, t_object *object)
{
	t_object_explosion		*data;

	data = (t_object_explosion *)object->data;
	data->position.x = gui_entry_get_f(gui->position_x);
	data->position.y = gui_entry_get_f(gui->position_y);
	data->position.z = gui_entry_get_f(gui->position_z);
	data->radius = gui_entry_get_f(gui->radius);
	data->noise_amplitude = gui_entry_get_f(gui->noise);
}

void						gui_object_explosion_clear
	(t_gui_object_explosion *gui)
{
	gtk_entry_set_text(gui->position_x, "");
	gtk_entry_set_text(gui->position_y, "");
	gtk_entry_set_text(gui->position_z, "");
	gtk_entry_set_text(gui->radius, "");
	gtk_entry_set_text(gui->noise, "");
}

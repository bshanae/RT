/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_torus_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:40:35 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 15:40:35 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x.h"

t_gui_object_torus			gui_object_torus_init
	(t_gui_init_torus *init, GtkBuilder *builder)
{
	t_gui_object_torus		torus;

	torus.position_x = RT_GUI_GET(builder, init->position_x);
	torus.position_y = RT_GUI_GET(builder, init->position_y);
	torus.position_z = RT_GUI_GET(builder, init->position_z);
	torus.width = RT_GUI_GET(builder, init->width);
	torus.radius = RT_GUI_GET(builder, init->radius);
	return (torus);
}

void						gui_object_torus_get
	(t_gui_object_torus *gui, t_object *object)
{
	t_object_torus		*data;

	data = (t_object_torus *)object->data;
	gui_entry_set_f(gui->position_x, data->position.x);
	gui_entry_set_f(gui->position_y, data->position.y);
	gui_entry_set_f(gui->position_z, data->position.z);
	gui_entry_set_f(gui->radius, data->radius);
	gui_entry_set_f(gui->width, data->width);
}

void						gui_object_torus_set
	(t_gui_object_torus *gui, t_object *object)
{
	t_object_torus	*data;

	data = (t_object_torus *)object->data;
	data->position.x = gui_entry_get_f(gui->position_x);
	data->position.y = gui_entry_get_f(gui->position_y);
	data->position.z = gui_entry_get_f(gui->position_z);
	data->radius = gui_entry_get_f(gui->radius);
	data->width = gui_entry_get_f(gui->width);
}

void						gui_object_torus_clear
	(t_gui_object_torus *gui)
{
	gtk_entry_set_text(gui->position_x, "");
	gtk_entry_set_text(gui->position_y, "");
	gtk_entry_set_text(gui->position_z, "");
	gtk_entry_set_text(gui->width, "");
	gtk_entry_set_text(gui->radius, "");
}

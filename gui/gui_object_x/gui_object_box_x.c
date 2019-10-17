/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_box_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:26:21 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x.h"

t_gui_object_box			gui_object_box_init
	(t_gui_init_box *init, GtkBuilder *builder)
{
	t_gui_object_box		box;

	box.position_x = RT_GUI_GET(builder, init->position_x);
	box.position_y = RT_GUI_GET(builder, init->position_y);
	box.position_z = RT_GUI_GET(builder, init->position_z);
	box.size_x = RT_GUI_GET(builder, init->size_x);
	box.size_y = RT_GUI_GET(builder, init->size_y);
	box.size_z = RT_GUI_GET(builder, init->size_z);
	return (box);
}

void						gui_object_box_get
	(t_gui_object_box *gui, t_object *object)
{
	t_object_box			*data;

	data = (t_object_box *)object->data;
	gui_entry_set_f(gui->position_x, data->position.x);
	gui_entry_set_f(gui->position_y, data->position.y);
	gui_entry_set_f(gui->position_z, data->position.z);
	gui_entry_set_f(gui->size_x, data->size.x);
	gui_entry_set_f(gui->size_y, data->size.y);
	gui_entry_set_f(gui->size_z, data->size.z);
}

void						gui_object_box_set
	(t_gui_object_box *gui, t_object *object)
{
	t_object_box *data;

	data = (t_object_box *)object->data;
	data->position.x = gui_entry_get_f(gui->position_x);
	data->position.y = gui_entry_get_f(gui->position_y);
	data->position.z = gui_entry_get_f(gui->position_z);
	data->size.x = gui_entry_get_f(gui->size_x);
	data->size.y = gui_entry_get_f(gui->size_y);
	data->size.z = gui_entry_get_f(gui->size_z);
}

void						gui_object_box_clear
	(t_gui_object_box *gui)
{
	gtk_entry_set_text(gui->position_x, "");
	gtk_entry_set_text(gui->position_y, "");
	gtk_entry_set_text(gui->position_z, "");
	gtk_entry_set_text(gui->size_x, "");
	gtk_entry_set_text(gui->size_y, "");
	gtk_entry_set_text(gui->size_z, "");
}

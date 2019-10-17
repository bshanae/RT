/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_moebius_x.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:32:41 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x.h"

t_gui_object_moebius		gui_object_moebius_init
	(t_gui_init_moebius *init, GtkBuilder *builder)
{
	t_gui_object_moebius	moebius;

	moebius.position_x = RT_GUI_GET(builder, init->position_x);
	moebius.position_y = RT_GUI_GET(builder, init->position_y);
	moebius.position_z = RT_GUI_GET(builder, init->position_z);
	moebius.radius = RT_GUI_GET(builder, init->radius);
	moebius.width = RT_GUI_GET(builder, init->width);
	return (moebius);
}

void						gui_object_moebius_get
	(t_gui_object_moebius *gui, t_object *object)
{
	t_object_moebius		*data;

	data = (t_object_moebius *)object->data;
	gui_entry_set_f(gui->position_x, data->position.x);
	gui_entry_set_f(gui->position_y, data->position.y);
	gui_entry_set_f(gui->position_z, data->position.z);
	gui_entry_set_f(gui->radius, data->radius);
	gui_entry_set_f(gui->width, 2 * data->half_width);
}

void						gui_object_moebius_set
	(t_gui_object_moebius *gui, t_object *object)
{
	t_object_moebius		*data;

	data = (t_object_moebius *)object->data;
	data->position.x = gui_entry_get_f(gui->position_x);
	data->position.y = gui_entry_get_f(gui->position_y);
	data->position.z = gui_entry_get_f(gui->position_z);
	data->radius = gui_entry_get_f(gui->radius);
	data->half_width = gui_entry_get_f(gui->width) / 2.;
}

void						gui_object_moebius_clear
	(t_gui_object_moebius *gui)
{
	gtk_entry_set_text(gui->position_x, "");
	gtk_entry_set_text(gui->position_y, "");
	gtk_entry_set_text(gui->position_z, "");
	gtk_entry_set_text(gui->radius, "");
	gtk_entry_set_text(gui->width, "");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_paraboloid_x.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:39:16 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x.h"

t_gui_object_paraboloid		gui_object_paraboloid_init
	(t_gui_init_paraboloid *init, GtkBuilder *builder)
{
	t_gui_object_paraboloid	paraboloid;

	paraboloid.extremum_x = RT_GUI_GET(builder, init->extremum_x);
	paraboloid.extremum_y = RT_GUI_GET(builder, init->extremum_y);
	paraboloid.extremum_z = RT_GUI_GET(builder, init->extremum_z);
	paraboloid.axis_x = RT_GUI_GET(builder, init->axis_x);
	paraboloid.axis_y = RT_GUI_GET(builder, init->axis_y);
	paraboloid.axis_z = RT_GUI_GET(builder, init->axis_z);
	paraboloid.radius = RT_GUI_GET(builder, init->radius);
	return (paraboloid);
}

void						gui_object_paraboloid_get
	(t_gui_object_paraboloid *gui, t_object *object)
{
	t_object_paraboloid		*data;

	data = (t_object_paraboloid *)object->data;
	gui_entry_set_f(gui->extremum_x, data->extremum.x);
	gui_entry_set_f(gui->extremum_y, data->extremum.y);
	gui_entry_set_f(gui->extremum_z, data->extremum.z);
	gui_entry_set_f(gui->axis_x, data->axis.x);
	gui_entry_set_f(gui->axis_y, data->axis.y);
	gui_entry_set_f(gui->axis_z, data->axis.z);
	gui_entry_set_f(gui->radius, data->radius);
}

void						gui_object_paraboloid_set
	(t_gui_object_paraboloid *gui, t_object *object)
{
	t_object_paraboloid		*data;

	data = (t_object_paraboloid *)object->data;
	data->extremum.x = gui_entry_get_f(gui->extremum_x);
	data->extremum.y = gui_entry_get_f(gui->extremum_y);
	data->extremum.z = gui_entry_get_f(gui->extremum_z);
	data->axis.x = gui_entry_get_f(gui->axis_x);
	data->axis.y = gui_entry_get_f(gui->axis_y);
	data->axis.z = gui_entry_get_f(gui->axis_z);
	data->radius = gui_entry_get_f(gui->radius);
}

void						gui_object_paraboloid_clear
	(t_gui_object_paraboloid *gui)
{
	gtk_entry_set_text(gui->extremum_x, "");
	gtk_entry_set_text(gui->extremum_y, "");
	gtk_entry_set_text(gui->extremum_z, "");
	gtk_entry_set_text(gui->axis_x, "");
	gtk_entry_set_text(gui->axis_y, "");
	gtk_entry_set_text(gui->axis_z, "");
	gtk_entry_set_text(gui->radius, "");
}

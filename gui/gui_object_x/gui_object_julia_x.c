/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_julia_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:29:53 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x.h"

t_gui_object_julia			gui_object_julia_init
	(t_gui_init_julia *init, GtkBuilder *builder)
{
	t_gui_object_julia		julia;

	julia.iterations = RT_GUI_GET(builder, init->iterations);
	julia.value_x = RT_GUI_GET(builder, init->value_x);
	julia.value_y = RT_GUI_GET(builder, init->value_y);
	julia.value_z = RT_GUI_GET(builder, init->value_z);
	julia.value_w = RT_GUI_GET(builder, init->value_w);
	return (julia);
}

void						gui_object_julia_get
	(t_gui_object_julia *gui, t_object *object)
{
	t_object_julia			*data;

	data = (t_object_julia *)object->data;
	gui_entry_set_i(gui->iterations, data->iterations);
	gui_entry_set_f(gui->value_x, data->value.x);
	gui_entry_set_f(gui->value_y, data->value.y);
	gui_entry_set_f(gui->value_z, data->value.z);
	gui_entry_set_f(gui->value_w, data->value.w);
}

void						gui_object_julia_set
	(t_gui_object_julia *gui, t_object *object)
{
	t_object_julia			*data;

	data = (t_object_julia *)object->data;
	data->iterations = gui_entry_get_i(gui->iterations);
	data->value.x = gui_entry_get_f(gui->value_x);
	data->value.y = gui_entry_get_f(gui->value_y);
	data->value.z = gui_entry_get_f(gui->value_z);
	data->value.w = gui_entry_get_f(gui->value_w);
}

void						gui_object_julia_clear
	(t_gui_object_julia *gui)
{
	gtk_entry_set_text(gui->iterations, "");
	gtk_entry_set_text(gui->value_x, "");
	gtk_entry_set_text(gui->value_y, "");
	gtk_entry_set_text(gui->value_z, "");
	gtk_entry_set_text(gui->value_w, "");
}

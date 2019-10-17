/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_cylinder_x.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:27:48 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x.h"

t_gui_object_cylinder		gui_object_cylinder_init
	(t_gui_init_cylinder *init, GtkBuilder *builder)
{
	t_gui_object_cylinder cylinder;

	cylinder.top_x = GTK_ENTRY(RT_GUI_GET(builder, init->top_x));
	cylinder.top_y = GTK_ENTRY(RT_GUI_GET(builder, init->top_y));
	cylinder.top_z = GTK_ENTRY(RT_GUI_GET(builder, init->top_z));
	cylinder.bottom_x = GTK_ENTRY(RT_GUI_GET(builder, init->bottom_x));
	cylinder.bottom_y = GTK_ENTRY(RT_GUI_GET(builder, init->bottom_y));
	cylinder.bottom_z = GTK_ENTRY(RT_GUI_GET(builder, init->bottom_z));
	cylinder.radius = GTK_ENTRY(RT_GUI_GET(builder, init->radius));
	return (cylinder);
}

void						gui_object_cylinder_get
	(t_gui_object_cylinder *gui, t_object *object)
{
	t_object_cylinder			*data;

	data = (t_object_cylinder *)object->data;
	gui_entry_set_f(gui->top_x, data->top.x);
	gui_entry_set_f(gui->top_y, data->top.y);
	gui_entry_set_f(gui->top_z, data->top.z);
	gui_entry_set_f(gui->bottom_x, data->bottom.x);
	gui_entry_set_f(gui->bottom_y, data->bottom.y);
	gui_entry_set_f(gui->bottom_z, data->bottom.z);
	gui_entry_set_f(gui->radius, data->radius);
}

void						gui_object_cylinder_set
	(t_gui_object_cylinder *gui, t_object *object)
{
	t_object_cylinder		*data;

	data = (t_object_cylinder *)object->data;
	data->top.x = gui_entry_get_f(gui->top_x);
	data->top.y = gui_entry_get_f(gui->top_y);
	data->top.z = gui_entry_get_f(gui->top_z);
	data->bottom.x = gui_entry_get_f(gui->bottom_x);
	data->bottom.y = gui_entry_get_f(gui->bottom_y);
	data->bottom.z = gui_entry_get_f(gui->bottom_z);
	data->radius = gui_entry_get_f(gui->radius);
	data->axis = f4_normalize(f4_sub(data->top, data->bottom));
	data->length_line = f4_length(f4_sub(data->top, data->bottom));
	data->length = data->length_line + data->radius * 2;
}

void						gui_object_cylinder_clear
	(t_gui_object_cylinder *gui)
{
	gtk_entry_set_text(gui->top_x, "");
	gtk_entry_set_text(gui->top_y, "");
	gtk_entry_set_text(gui->top_z, "");
	gtk_entry_set_text(gui->bottom_x, "");
	gtk_entry_set_text(gui->bottom_y, "");
	gtk_entry_set_text(gui->bottom_z, "");
	gtk_entry_set_text(gui->radius, "");
}

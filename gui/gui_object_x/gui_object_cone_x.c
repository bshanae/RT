/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_cone_x.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:27:18 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x.h"

t_gui_object_cone		gui_object_cone_init
	(t_gui_init_cone *init, GtkBuilder *builder)
{
	t_gui_object_cone	cone;

	cone.top_x = RT_GUI_GET(builder, init->top_x);
	cone.top_y = RT_GUI_GET(builder, init->top_y);
	cone.top_z = RT_GUI_GET(builder, init->top_z);
	cone.bottom_x = RT_GUI_GET(builder, init->bottom_x);
	cone.bottom_y = RT_GUI_GET(builder, init->bottom_y);
	cone.bottom_z = RT_GUI_GET(builder, init->bottom_z);
	cone.radius = RT_GUI_GET(builder, init->radius);
	return (cone);
}

void					gui_object_cone_get
	(t_gui_object_cone *gui, t_object *object)
{
	t_object_cone		*data;

	data = (t_object_cone *)object->data;
	gui_entry_set_f(gui->top_x, data->top.x);
	gui_entry_set_f(gui->top_y, data->top.y);
	gui_entry_set_f(gui->top_z, data->top.z);
	gui_entry_set_f(gui->bottom_x, data->bottom.x);
	gui_entry_set_f(gui->bottom_y, data->bottom.y);
	gui_entry_set_f(gui->bottom_z, data->bottom.z);
	gui_entry_set_f(gui->radius, data->radius);
}

void					gui_object_cone_set
	(t_gui_object_cone *gui, t_object *object)
{
	t_object_cone		*data;
	RT_F4_API			temp_axis;
	RT_F				hypotenuse;
	RT_F				height;

	data = (t_object_cone *)object->data;
	data->top.x = gui_entry_get_f(gui->top_x);
	data->top.y = gui_entry_get_f(gui->top_y);
	data->top.z = gui_entry_get_f(gui->top_z);
	data->bottom.x = gui_entry_get_f(gui->bottom_x);
	data->bottom.y = gui_entry_get_f(gui->bottom_y);
	data->bottom.z = gui_entry_get_f(gui->bottom_z);
	data->radius = gui_entry_get_f(gui->radius);
	temp_axis = f4_sub(data->bottom, data->top);
	data->tangent = data->radius / f4_length(temp_axis);
	data->axis = f4_normalize(temp_axis);
	height = f4_length(f4_sub(data->top, data->bottom));
	hypotenuse = RT_SQRT_API(RT_POW(height, 2.) + data->radius * data->radius);
	data->length = hypotenuse + data->radius;
}

void					gui_object_cone_clear
	(t_gui_object_cone *gui)
{
	gtk_entry_set_text(gui->top_x, "");
	gtk_entry_set_text(gui->top_y, "");
	gtk_entry_set_text(gui->top_z, "");
	gtk_entry_set_text(gui->bottom_x, "");
	gtk_entry_set_text(gui->bottom_y, "");
	gtk_entry_set_text(gui->bottom_z, "");
	gtk_entry_set_text(gui->radius, "");
}

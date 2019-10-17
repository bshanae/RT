/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_sphere_x.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:40:14 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x.h"

t_gui_object_sphere		gui_object_sphere_init
	(t_gui_init_sphere *init, GtkBuilder *builder)
{
	t_gui_object_sphere	sphere;

	sphere.position_x = RT_GUI_GET(builder, init->position_x);
	sphere.position_y = RT_GUI_GET(builder, init->position_y);
	sphere.position_z = RT_GUI_GET(builder, init->position_z);
	sphere.radius = RT_GUI_GET(builder, init->radius);
	return (sphere);
}

void					gui_object_sphere_get
	(t_gui_object_sphere *gui, t_object *object)
{
	t_object_sphere		*data;

	data = (t_object_sphere *)object->data;
	gui_entry_set_f(gui->position_x, data->position.x);
	gui_entry_set_f(gui->position_y, data->position.y);
	gui_entry_set_f(gui->position_z, data->position.z);
	gui_entry_set_f(gui->radius, data->radius);
}

void					gui_object_sphere_set
	(t_gui_object_sphere *gui, t_object *object)
{
	t_object_sphere	*data;

	data = (t_object_sphere *)object->data;
	data->position.x = gui_entry_get_f(gui->position_x);
	data->position.y = gui_entry_get_f(gui->position_y);
	data->position.z = gui_entry_get_f(gui->position_z);
	data->radius = gui_entry_get_f(gui->radius);
}

void					gui_object_sphere_clear(t_gui_object_sphere *gui)
{
	gtk_entry_set_text(gui->position_x, "");
	gtk_entry_set_text(gui->position_y, "");
	gtk_entry_set_text(gui->position_z, "");
	gtk_entry_set_text(gui->radius, "");
}

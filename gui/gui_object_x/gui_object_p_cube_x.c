/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_p_cube_x.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:37:29 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x.h"

t_gui_object_p_cube				gui_object_p_cube_init
	(t_gui_init_p_cube *init, GtkBuilder *builder)
{
	t_gui_object_p_cube			p_cube;

	p_cube.position_x = RT_GUI_GET(builder, init->position_x);
	p_cube.position_y = RT_GUI_GET(builder, init->position_y);
	p_cube.position_z = RT_GUI_GET(builder, init->position_z);
	p_cube.iterations = RT_GUI_GET(builder, init->iterations);
	return (p_cube);
}

void							gui_object_p_cube_get
	(t_gui_object_p_cube *gui, t_object *object)
{
	t_object_perforated_cube	*data;

	data = (t_object_perforated_cube *)object->data;
	gui_entry_set_f(gui->position_x, data->position.x);
	gui_entry_set_f(gui->position_y, data->position.y);
	gui_entry_set_f(gui->position_z, data->position.z);
	gui_entry_set_i(gui->iterations, data->iterations);
}

void							gui_object_p_cube_set
	(t_gui_object_p_cube *gui, t_object *object)
{
	t_object_perforated_cube	*data;

	data = (t_object_perforated_cube *)object->data;
	data->position.x = gui_entry_get_f(gui->position_x);
	data->position.y = gui_entry_get_f(gui->position_y);
	data->position.z = gui_entry_get_f(gui->position_z);
	data->iterations = gui_entry_get_i(gui->iterations);
}

void							gui_object_p_cube_clear
	(t_gui_object_p_cube *gui)
{
	gtk_entry_set_text(gui->position_x, "");
	gtk_entry_set_text(gui->position_y, "");
	gtk_entry_set_text(gui->position_z, "");
	gtk_entry_set_text(gui->iterations, "");
}

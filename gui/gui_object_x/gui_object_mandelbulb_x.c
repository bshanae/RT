/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_object_mandelbulb_x.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:32:08 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_object_x.h"

t_gui_object_mandelbulb		gui_object_mandelbulb_init
	(t_gui_init_mandelbulb *init, GtkBuilder *builder)
{
	t_gui_object_mandelbulb	mandelbulb;

	mandelbulb.iterations = RT_GUI_GET(builder, init->iterations);
	mandelbulb.power = RT_GUI_GET(builder, init->power);
	return (mandelbulb);
}

void						gui_object_mandelbulb_get
	(t_gui_object_mandelbulb *gui, t_object *object)
{
	t_object_mandelbulb		*data;

	data = (t_object_mandelbulb *)object->data;
	gui_entry_set_i(gui->iterations, data->iterations);
	gui_entry_set_f(gui->power, data->power);
}

void						gui_object_mandelbulb_set
	(t_gui_object_mandelbulb *gui, t_object *object)
{
	t_object_mandelbulb		*data;

	data = (t_object_mandelbulb *)object->data;
	data->iterations = gui_entry_get_i(gui->iterations);
	data->power = gui_entry_get_f(gui->power);
}

void						gui_object_mandelbulb_clear
	(t_gui_object_mandelbulb *gui)
{
	gtk_entry_set_text(gui->iterations, "");
	gtk_entry_set_text(gui->power, "");
}

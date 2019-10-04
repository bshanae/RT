/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_camera_focus_x.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:28:14 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:28:16 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_x.h"

gboolean			gui_signal_camera_focus_state
	(GtkWidget *widget, gboolean state, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->renderer->data.camera->focus = state;
	gtk_widget_set_sensitive(GTK_WIDGET(gui->camera->focus_box), state);
	cl_renderer_flag_set(gui->renderer, cl_flag_update_camera);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	gui_queue_push(gui->queue);
	return (FALSE);
}

void				gui_signal_camera_focus_auto
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui->camera->focus_request = 1;
	gtk_widget_set_sensitive(GTK_WIDGET(gui->notebook), 0);
}

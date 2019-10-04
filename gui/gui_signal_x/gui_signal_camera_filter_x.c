/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_camera_filter_x.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:27:50 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:27:56 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_x.h"

void				gui_signal_camera_filter
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	t_camera		*camera;
	int				state[4];
	t_rt_filter_mod	state_i;

	gui = (t_gui *)ptr;
	camera = gui->renderer->data.camera;
	state[0] = gtk_toggle_button_get_active(gui->camera->filter_none);
	state[1] = gtk_toggle_button_get_active(gui->camera->filter_cartoon);
	state[2] = gtk_toggle_button_get_active(gui->camera->filter_sepia);
	state[3] = gtk_toggle_button_get_active(gui->camera->filter_stereo);
	state_i = 0;
	while (state_i < rt_filter_end)
		if (state[state_i])
			break ;
		else
			state_i++;
	camera->filter_mod = state_i;
	cl_renderer_flag_set(gui->renderer, cl_flag_update_camera);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	gui_queue_push(gui->queue);
	gui_queue_execute_force(gui->queue);
}

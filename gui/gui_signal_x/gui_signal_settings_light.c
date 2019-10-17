/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_settings_light.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:59:51 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_x.h"

void				gui_signal_settings_light
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	int				state[2];

	gui = (t_gui *)ptr;
	state[0] = gtk_toggle_button_get_active(gui->settings->light_basic);
	state[1] = gtk_toggle_button_get_active(gui->settings->light_area);
	cl_renderer_change_light_mod(gui->renderer,
		state[0] ? rt_light_basic : rt_light_area);
	gui_scene_common_update_all_wrapped(gui->scene->common);
	gui_camera_show(gui->camera);
	gui_queue_push(gui->queue);
}

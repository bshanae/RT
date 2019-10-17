/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_scene_edit_apply.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:52:18 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_x.h"

void				gui_signal_scene_edit_apply
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	cl_renderer_change_background(gui->renderer,
		gui_scene_edit_background_read_value(gui->scene->edit));
	if (gui->scene->edit->current_id != -1)
	{
		gui_scene_edit_apply(gui->scene->edit, gui->renderer->data.scene);
		scene_update(gui->renderer->data.scene);
		gui_scene_common_update_limited_wrapped(gui->scene->common);
		gui_scene_common_update_csg_wrapped(gui->scene->common);
	}
	gui_control_hide(&gui->scene->edit->control);
	cl_renderer_flag_set(gui->renderer, cl_flag_update_scene);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	gui_queue_push(gui->queue);
}

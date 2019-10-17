/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_commnad_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:18:40 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:28 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void				gui_command_focus(t_gui *gui, GdkEventButton *event)
{
	gui->camera->focus_request = 0;
	gui_queue_block(gui->queue);
	cl_renderer_camera_request_focus(gui->renderer, event->x, event->y);
	gui_queue_execute_force(gui->queue);
	gui_queue_unblock(gui->queue);
	gui_queue_wait(gui->queue);
	gui_camera_show(gui->camera);
	gtk_widget_set_sensitive(GTK_WIDGET(gui->notebook), 1);
}

void				gui_command_select(t_gui *gui, GdkEventButton *event)
{
	gui_queue_block(gui->queue);
	cl_renderer_camera_request_select(gui->renderer, event->x, event->y);
	gui_queue_execute_force(gui->queue);
	gui_queue_unblock(gui->queue);
	gui_queue_wait(gui->queue);
	gui_scene_edit_select(gui->scene->edit, gui->renderer->data.scene);
}

void				gui_command_unselect(t_gui *gui)
{
	gui->scene->edit->selection_silent = rt_true;
	gui->scene->edit->current_id = -1;
	scene_unselect(gui->renderer->data.scene);
	gui_scene_edit_unselect(gui->scene->edit);
	cl_renderer_flag_set(gui->renderer, cl_flag_update_camera);
	cl_renderer_flag_set(gui->renderer, cl_flag_update_scene);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	gui_queue_execute_force(gui->queue);
	gui->scene->edit->selection_silent = rt_false;
}

void				gui_command_move(t_gui *gui, t_rt_movement movement)
{
	gui->scene->edit->control.silent = rt_true;
	gui_scene_edit_show(gui->scene->edit,
		gui->renderer->data.scene->objects + gui->scene->edit->current_id);
	cl_renderer_object_move(gui->renderer, movement);
	gui->scene->edit->control.silent = rt_false;
}

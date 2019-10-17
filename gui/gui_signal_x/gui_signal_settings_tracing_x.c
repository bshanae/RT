/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_settings_tracing_x.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:01:09 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_x.h"

void				gui_signal_settings_tracing_rt
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	gboolean		state;

	gui = (t_gui *)ptr;
	if (gui->settings->tracing_block == rt_true)
		return ;
	gui->settings->tracing_block = rt_true;
	state = gtk_toggle_button_get_active(gui->settings->tracing_rt);
	gtk_toggle_button_set_active(gui->settings->tracing_rm, !state);
	gui->settings->tracing_block = rt_false;
	gtk_stack_set_visible_child_name(gui->settings->stack, state ? "rt" : "rm");
	cl_renderer_change_tracing_mod(gui->renderer, state ?
	rt_tracing_rt : rt_tracing_rm);
	gui_scene_common_update_all_wrapped(gui->scene->common);
	gui_queue_push(gui->queue);
}

void				gui_signal_settings_tracing_rm
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	gboolean		state;

	gui = (t_gui *)ptr;
	if (gui->settings->tracing_block == rt_true)
		return ;
	gui->settings->tracing_block = rt_true;
	state = gtk_toggle_button_get_active(gui->settings->tracing_rt);
	gtk_toggle_button_set_active(gui->settings->tracing_rt, !state);
	gui->settings->tracing_block = rt_false;
	gtk_stack_set_visible_child_name(gui->settings->stack, state ? "rm" : "rt");
	cl_renderer_change_tracing_mod(gui->renderer, state ?
		rt_tracing_rm : rt_tracing_rt);
	gui_scene_common_update_all_wrapped(gui->scene->common);
	gui_queue_push(gui->queue);
}

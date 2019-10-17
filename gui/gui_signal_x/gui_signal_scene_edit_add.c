/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_scene_edit_add.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:51:58 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_x.h"

void				gui_signal_scene_edit_add
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	int				response;

	gui = (t_gui *)ptr;
	gui->scene->edit->control.silent = rt_true;
	gui->scene->edit->selection_silent = rt_true;
	gui_scene_add_prepare(gui->scene->add);
	response = gtk_dialog_run(gui->scene->add->dialog);
	if (response == GTK_RESPONSE_YES)
	{
		scene_update(gui->renderer->data.scene);
		gui_scene_common_update_all_wrapped(gui->scene->common);
		cl_renderer_flag_set(gui->renderer, cl_flag_update_scene);
		cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
		gui_queue_push(gui->queue);
		gui_scene_edit_unselect(gui->scene->edit);
	}
	gtk_widget_hide(GTK_WIDGET(gui->scene->add->dialog));
	gui->scene->edit->control.silent = rt_false;
	gui->scene->edit->selection_silent = rt_false;
}

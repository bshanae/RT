/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_scene_edit_remove.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:53:01 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 14:02:16 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_x.h"

void					gui_signal_scene_edit_remove
	(GtkWidget *widget, gpointer ptr)
{
	t_gui				*gui;
	t_gui_scene_edit	*edit;
	int					test;
	int					response;

	gui = (t_gui *)ptr;
	edit = gui->scene->edit;
	test = gtk_list_store_iter_is_valid(edit->common->full, &edit->iter);
	if (!test)
		return (rt_raise_warning("GUI Signal : Scene edit iter is invalid"));
	response = gtk_dialog_run(gui->scene->edit->remove_dialog);
	gtk_widget_hide(GTK_WIDGET(gui->scene->edit->remove_dialog));
	if (response != GTK_RESPONSE_YES)
		return ;
	edit->selection_silent = rt_true;
	scene_object_remove(gui->renderer->data.scene, edit->current_id);
	gui_scene_common_update_all_wrapped(gui->scene->common);
	gui_scene_edit_unselect(gui->scene->edit);
	cl_renderer_flag_set(gui->renderer, cl_flag_update_scene);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	gui_queue_push(gui->queue);
	edit->selection_silent = rt_false;
}

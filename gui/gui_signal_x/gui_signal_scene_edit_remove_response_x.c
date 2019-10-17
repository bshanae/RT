/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_scene_edit_remove_response_x.c          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:53:25 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_x.h"

void				gui_signal_scene_edit_remove_response_cancel
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gtk_dialog_response(gui->scene->edit->remove_dialog, GTK_RESPONSE_CANCEL);
}

void				gui_signal_scene_edit_remove_response_yes
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	t_object		*space;

	gui = (t_gui *)ptr;
	gtk_dialog_response(gui->scene->edit->remove_dialog, GTK_RESPONSE_YES);
}

void				gui_signal_scene_edit_remove_response_no
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gtk_dialog_response(gui->scene->edit->remove_dialog, GTK_RESPONSE_NO);
}

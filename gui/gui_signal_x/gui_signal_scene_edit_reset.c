/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_scene_edit_reset.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:53:43 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_x.h"

void				gui_signal_scene_edit_reset
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	t_object		*object;

	gui = (t_gui *)ptr;
	if (gui->scene->edit->current_id != -1)
	{
		object = gui->renderer->data.scene->objects +
			gui->scene->edit->current_id;
		gui_scene_edit_show(gui->scene->edit, object);
	}
	gui_scene_edit_background_get(gui->scene->edit, gui->renderer->data.scene);
	gui_control_hide(&gui->scene->edit->control);
}

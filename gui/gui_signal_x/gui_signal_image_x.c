/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_image_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:46:27 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:46:39 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_x.h"

static int			static_is_left_click(GdkEventButton *event)
{
	return (event->type == GDK_BUTTON_PRESS && event->button == 1);
}

static int			static_is_right_click(GdkEventButton *event)
{
	return (event->type == GDK_BUTTON_PRESS && event->button == 3);
}

gboolean			gui_signal_image_click
	(GtkWidget *widget, GdkEventButton *event, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	if (gui->camera->focus_request)
		gui_command_focus(gui, event);
	if (!gtk_widget_is_focus(GTK_WIDGET(gui->image->event_box)))
	{
		gtk_widget_grab_focus(GTK_WIDGET(gui->image->event_box));
		return (TRUE);
	}
	if (static_is_left_click(event))
		gui_command_select(gui, event);
	else if (static_is_right_click(event))
		gui_command_unselect(gui);
	return (TRUE);
}

gboolean			gui_signal_image_draw
	(GtkWidget *widget, void *cairo, gpointer ptr)
{
	t_gui			*gui;
	GtkAllocation	allocation;

	gui = (t_gui *)ptr;
	if (gui->image->resize_request == rt_false)
		return (FALSE);
	gtk_widget_get_allocation(widget, &allocation);
	gui->image->width = allocation.width;
	gui->image->height = allocation.height;
	gui_image_allocate(gui->image);
	gui->image->resize_request = rt_false;
	gui_resize_finish(gui);
	return (FALSE);
}

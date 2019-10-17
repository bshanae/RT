/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:26:45 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_x.h"

static int			try_move_camera(t_gui *gui, int key)
{
	t_rt_movement	movement;

	if (key == GDK_KEY_a || key == GDK_KEY_Cyrillic_ef)
		movement = rt_movement_left;
	else if (key == GDK_KEY_d || key == GDK_KEY_Cyrillic_ve)
		movement = rt_movement_right;
	else if (key == GDK_KEY_w || key == GDK_KEY_Cyrillic_tse)
		movement = rt_movement_forward;
	else if (key == GDK_KEY_s || key == GDK_KEY_Cyrillic_yeru)
		movement = rt_movement_backward;
	else if (key == GDK_KEY_q || key == GDK_KEY_Cyrillic_shorti)
		movement = rt_movement_up;
	else if (key == GDK_KEY_e || key == GDK_KEY_Cyrillic_u)
		movement = rt_movement_down;
	else
		return (0);
	if (gui->renderer->data.scene->selected_id != -1)
		gui_command_move(gui, movement);
	else
	{
		cl_renderer_camera_move(gui->renderer, movement);
		gui_camera_show(gui->camera);
	}
	gui_queue_execute_force(gui->queue);
	return (1);
}

static int			try_rotate_camera(t_gui *gui, int key)
{
	if (gui->renderer->data.scene->selected_id != -1)
		return (0);
	if (key == GDK_KEY_Left)
		cl_renderer_camera_rotate(gui->renderer, rt_rotation_y,
			rt_rotation_positive);
	else if (key == GDK_KEY_Right)
		cl_renderer_camera_rotate(gui->renderer, rt_rotation_y,
			rt_rotation_negative);
	else if (key == GDK_KEY_Up)
		cl_renderer_camera_rotate(gui->renderer, rt_rotation_x,
			rt_rotation_negative);
	else if (key == GDK_KEY_Down)
		cl_renderer_camera_rotate(gui->renderer, rt_rotation_x,
			rt_rotation_positive);
	else
		return (0);
	gui_camera_show(gui->camera);
	gui_queue_execute_force(gui->queue);
	return (1);
}

#ifdef RT_QUEUE_AUTO

static int			static_command
	(GtkWidget *widget, GdkEventKey *event, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	if (event->keyval == GDK_KEY_Escape)
		gui_signal_exit(widget, ptr);
	else if (event->keyval == GDK_KEY_Return)
		gui->queue->block = !gui->queue->block;
	else if (event->keyval == GDK_KEY_r)
	{
		cl_renderer_camera_reset(gui->renderer);
		gui_camera_show(gui->camera);
		gui_queue_execute_force(gui->queue);
	}
	else
		return (0);
	return (1);
}

#elif defined RT_QUEUE_MANUAL

static int			static_command
	(GtkWidget *widget, GdkEventKey *event, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	if (event->keyval == GDK_KEY_Escape)
		gui_signal_exit(widget, ptr);
	else if (event->keyval == GDK_KEY_Return)
		gui_queue_execute_force(gui->queue);
	else if (event->keyval == GDK_KEY_r)
	{
		cl_renderer_camera_reset(gui->renderer);
		gui_camera_show(gui->camera);
		gui_queue_execute_force(gui->queue);
	}
	else
		return (0);
	return (1);
}

#endif

gboolean			gui_signal_key
	(GtkWidget *widget, GdkEventKey *event, gpointer ptr)
{
	t_gui			*gui;
	int				image_focus;

	gui = (t_gui *)ptr;
	if (static_command(widget, event, ptr))
		return (FALSE);
	image_focus = gtk_widget_is_focus(GTK_WIDGET(gui->image->event_box));
	if (image_focus && try_move_camera(gui, event->keyval))
		;
	else if (image_focus && try_rotate_camera(gui, event->keyval))
		;
	else
		return (FALSE);
	return (TRUE);
}

#include "gui_signal_x.h"

static int			static_is_left_click(GdkEventButton *event)
{
	return (event->type == GDK_BUTTON_PRESS && event->button == 1);
}

static int			static_is_right_click(GdkEventButton *event)
{
	return (event->type == GDK_BUTTON_PRESS && event->button == 3);
}

gboolean 			gui_signal_image_click
					(GtkWidget *widget, GdkEventButton *event, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	if (!gtk_widget_is_focus(GTK_WIDGET(gui->image->event_box)))
	{
		gtk_widget_grab_focus(GTK_WIDGET(gui->image->event_box));
		return (TRUE);
	}
	if (static_is_left_click(event) && gui->camera->focus_request)
	{
		gui->camera->focus_request = 0;
		gui_queue_block(gui->queue);
		cl_renderer_camera_request_focus(gui->renderer, event->x, event->y);
		gui_queue_execute_force(gui->queue);
		gui_queue_unblock(gui->queue);
		gui_queue_wait(gui->queue);
		gui_camera_show(gui->camera, gui->renderer->data.camera);
		gtk_widget_set_sensitive(GTK_WIDGET(gui->notebook), 1);
	}
	else if (static_is_left_click(event))
	{
		gui_queue_block(gui->queue);
		cl_renderer_camera_request_select(gui->renderer, event->x, event->y);
		gui_queue_execute_force(gui->queue);
		gui_queue_unblock(gui->queue);
		gtk_widget_set_sensitive(GTK_WIDGET(gui->notebook), 1);
	}
	else if (static_is_right_click(event))
	{
		gui->renderer->data.camera->select_request_object = -1;
		scene_unselect(gui->renderer->data.scene);
		cl_renderer_flag_set(gui->renderer, cl_flag_update_camera);
		cl_renderer_flag_set(gui->renderer, cl_flag_update_scene);
		cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
		gui_queue_execute_force(gui->queue);
	}
	return (TRUE);
}
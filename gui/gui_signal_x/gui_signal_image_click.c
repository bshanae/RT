#include "gui_signal_x.h"

gboolean 			gui_signal_image_click
					(GtkWidget *widget, GdkEventButton *event, gpointer ptr)
{
	t_gui			*gui;
	int 			is_second_stroke;

	gui = (t_gui *)ptr;
	is_second_stroke = gtk_widget_is_focus(GTK_WIDGET(gui->image->event_box));
	gtk_widget_grab_focus(GTK_WIDGET(gui->image->event_box));
	if (event->type == GDK_BUTTON_PRESS && is_second_stroke && gui->camera->focus_request)
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
	else if (event->type == GDK_BUTTON_PRESS && is_second_stroke)
	{
		printf("I've caught signal\n");
		gui_queue_block(gui->queue);
		printf("I've blocked queue\n");
		cl_renderer_camera_request_select(gui->renderer, event->x, event->y);
		gui_queue_execute_force(gui->queue);
		gui_queue_wait(gui->queue);
		gui_queue_unblock(gui->queue);
		printf("I've unblocked queue\n");
		gtk_widget_set_sensitive(GTK_WIDGET(gui->notebook), 1);
	}
	return (TRUE);
}
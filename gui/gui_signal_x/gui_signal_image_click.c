#include "gui_signal_x.h"

gboolean 			gui_signal_image_click
					(GtkWidget *widget, GdkEventButton *event, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gtk_widget_grab_focus(GTK_WIDGET(gui->image->event_box));
	if (gui->camera->focus_request)
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
	return (TRUE);
}
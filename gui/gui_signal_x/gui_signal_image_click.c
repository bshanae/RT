#include "gui_signal_x.h"

gboolean 			gui_signal_image_click
					(GtkWidget *widget, GdkEventButton *event, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gtk_widget_grab_focus(GTK_WIDGET(gui->image->event_box));
	if (gui->camera->focus_request)
	{
		gui->renderer->data.camera->focus_request_x = event->x;
		gui->renderer->data.camera->focus_request_y = event->y;
		cl_renderer_flag_set(gui->renderer, cl_flag_update_camera);
		cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
		cl_renderer_render(gui->renderer);
		gtk_widget_set_sensitive(GTK_WIDGET(gui->notebook), 1);
	}
	return (TRUE);
}
#include "gui_signal_x.h"

void 				gui_signal_settings_apply
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	if (gui->resize_in_process == rt_true)
	{
		gui->image->resize_request = rt_true;
		gtk_widget_queue_draw(GTK_WIDGET(gui->image->event_box));
	}
	else
	{
		gui_settings_apply(gui->settings, &gui->renderer->data.settings);
		cl_renderer_flag_set(gui->renderer, cl_flag_update_settings);
		cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
		gui_queue_push(gui->queue);
	}
	gui_control_hide(&gui->settings->control);
}
#include "gui_signal_x.h"

void 				gui_signal_settings_reset
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	if (gui->resize_in_process == rt_true)
	{
		gtk_image_set_from_pixbuf(gui->image->image, gui->image->gdk_buffer);
		gui_resize_finish(gui);
	}
	else
		gui_settings_reset(gui->settings, &gui->renderer->data.settings);
	gui_control_hide(&gui->settings->control);
}
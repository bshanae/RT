#include "gui_signal_x.h"

void 				gui_signal_settings_resize
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;

	gui_resize_start(gui);
	gtk_image_clear(gui->image->image);
	gui_control_show(&gui->settings->control);
}
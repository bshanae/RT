#include "gui_signal_x.h"

gboolean 			gui_signal_image_click
					(GtkWidget *event_box, GdkEventButton *event, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gtk_widget_grab_focus(GTK_WIDGET(gui->image->event_box));
	return (TRUE);
}
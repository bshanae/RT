#include "gui.h"
#include "gui_signal.h"

void				gui_init(t_gui *gui, int *ac, char ***av)
{
	gtk_init(ac, av);

	gui->builder = gtk_builder_new_from_file(G_SOURCE);
	gui->window = GTK_WINDOW(gtk_builder_get_object(gui->builder, G_WINDOW));
	gui_list_init(gui->list, gui->builder);
	gui_object_init(gui->object, gui->builder);
	//gui_image_init(gui->image, gui->builder);
	gui_signal_connect(gui);
	gtk_widget_show_all(GTK_WIDGET(gui->window));
}
#include "gui.h"

void				gui_init(t_gui *gui, int *ac, char ***av)
{
	gtk_init(ac, av);

	gui->builder = gtk_builder_new_from_file(G_SOURCE);
	gui->window = GTK_WINDOW(gtk_builder_get_object(gui->builder, G_WINDOW));
	gui_scene_init(gui->scene, gui->builder);
	gtk_builder_connect_signals(gui->builder, (gpointer)gui);
	gtk_widget_show(GTK_WIDGET(gui->window));
}
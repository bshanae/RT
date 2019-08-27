#include "gui_signal_x.h"

void 				gui_signal_parser_load
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	cl_renderer_load(gui->renderer, gui->parser->final_path);
	gtk_tree_selection_unselect_all(gui->parser->selection);
	gtk_button_set_label(gui->parser->dialog_run, "Choose scene file manually");
	gtk_widget_set_opacity(GTK_WIDGET(gui->parser->load), 0.);
	gui_update(gui);
}
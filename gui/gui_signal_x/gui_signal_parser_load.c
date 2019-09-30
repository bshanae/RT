#include "gui_signal_x.h"

void 				gui_signal_parser_load
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	cl_renderer_load(gui->renderer, gui->parser->final_path);
	gtk_tree_selection_unselect_all(gui->parser->selection);
	gtk_widget_set_opacity(GTK_WIDGET(gui->parser->load), 0.);
	scene_select(gui->renderer->data.scene, 0);
	gui_scene_edit_select(gui->scene->edit, gui->renderer->data.scene);
	gui_update(gui);
}
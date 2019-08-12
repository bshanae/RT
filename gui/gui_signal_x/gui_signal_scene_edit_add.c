#include "gui_signal_x.h"

void				gui_signal_scene_edit_add
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gtk_entry_set_placeholder_text(gui->scene->add->name,
		gui_scene_add_gen_name(gui->scene->add));
	gtk_widget_grab_focus(GTK_WIDGET(gui->scene->add->type_combo));
	gtk_dialog_run(gui->scene->add->dialog);
	gtk_widget_hide(GTK_WIDGET(gui->scene->add->dialog));
}
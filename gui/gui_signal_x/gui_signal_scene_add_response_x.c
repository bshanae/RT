#include "gui_signal_x.h"

void				gui_signal_scene_add_response_cancel
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gtk_dialog_response(gui->scene->add->dialog, GTK_RESPONSE_CANCEL);
}

void 				gui_signal_scene_add_response_yes
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	t_object		*space;

	gui = (t_gui *)ptr;
	gtk_dialog_response(gui->scene->add->dialog, GTK_RESPONSE_YES);
	space = scene_get_space(gui->renderer->data.scene);
	if (space)
		gui_scene_add_build_object(gui->scene->add, space);
	else
		rt_raise_warning("GUI Creator : No memory for new object");
}

void 				gui_signal_scene_add_response_no
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gtk_dialog_response(gui->scene->add->dialog, GTK_RESPONSE_NO);
}
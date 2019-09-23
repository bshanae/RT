#include "gui_signal_x.h"

void 				gui_signal_camera_state_reset
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	cl_renderer_camera_reset(gui->renderer);
	gui_camera_show(gui->camera);
	gtk_label_set_text(gui->camera->state_label, "Camera state has been reset");
	gtk_dialog_run(gui->camera->state_dialog);
	gtk_widget_hide(GTK_WIDGET(gui->camera->state_dialog));
}

void 				gui_signal_camera_state_save
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	cl_renderer_camera_save(gui->renderer);
	gui_camera_show(gui->camera);
	gtk_label_set_text(gui->camera->state_label, "Camera state has been saved");
	gtk_dialog_run(gui->camera->state_dialog);
	gtk_widget_hide(GTK_WIDGET(gui->camera->state_dialog));
}

void				gui_signal_camera_state_dialog_response
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gtk_dialog_response(gui->camera->state_dialog, GTK_RESPONSE_OK);
}

#include "gui_signal_x.h"

void				gui_signal_scene_edit_material_color
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	t_gui_color		color;

	gui = (t_gui *)ptr;
	gtk_color_button_get_rgba(gui->scene->edit->material.color_button, &color);
	gui_entry_set_f(gui->scene->edit->material.color_r, color.red);
	gui_entry_set_f(gui->scene->edit->material.color_g, color.green);
	gui_entry_set_f(gui->scene->edit->material.color_b, color.blue);
	gtk_widget_set_opacity(GTK_WIDGET(gui->scene->edit->control), 1.);
}

void				gui_signal_scene_edit_material_emission
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	t_gui_color		emission;

	gui = (t_gui *)ptr;
	gtk_color_button_get_rgba(gui->scene->edit->material.emission_button,
		&emission);
	gui_entry_set_f(gui->scene->edit->material.emission_r, emission.red);
	gui_entry_set_f(gui->scene->edit->material.emission_g, emission.green);
	gui_entry_set_f(gui->scene->edit->material.emission_b, emission.blue);
	gtk_widget_set_opacity(GTK_WIDGET(gui->scene->edit->control), 1.);
}
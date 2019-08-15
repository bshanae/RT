#include "gui_signal_x.h"

void 				gui_signal_scene_edit_material_color
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	t_object		*object;
	t_gui_color		color_gdk;

	gui = (t_gui *)ptr;
	if (gui->scene->edit->current_id == -1)
		return ;
	object = gui->renderer->data_host.scene->objects +
		gui->scene->edit->current_id;
	gtk_color_button_get_rgba(gui->scene->edit->material.color, &color_gdk);
	object->material.color = gui_color_to_f4(&color_gdk);
	gui->renderer->flags.update_scene = 1;
	cl_renderer_reset_samples(gui->renderer);
	cl_renderer_render(gui->renderer);
}

void 				gui_signal_scene_edit_material_emission
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	t_object		*object;
	t_gui_color		color_gdk;

	gui = (t_gui *)ptr;
	if (gui->scene->edit->current_id == -1)
		return ;
	object = gui->renderer->data_host.scene->objects +
		gui->scene->edit->current_id;
	gtk_color_button_get_rgba(gui->scene->edit->material.emission, &color_gdk);
	object->material.color = gui_color_to_f4(&color_gdk);
	gui->renderer->flags.update_scene = 1;
	cl_renderer_reset_samples(gui->renderer);
	cl_renderer_render(gui->renderer);
}
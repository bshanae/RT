#include "gui_signal_x.h"

void 				gui_signal_object_edit_plane_normal_x
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	RT_F			value;
	t_object		*object;

	gui = (t_gui *)ptr;
	if (gui->scene->edit->current_id == -1)
		return ;
	value = (RT_F)strtod(gtk_entry_get_text(GTK_ENTRY(widget)), NULL);
	object = gui->renderer->data.scene->objects +
			 gui->scene->edit->current_id;
	((t_object_plane *)object->data)->normal.x = value;
	cl_renderer_flag_set(gui->renderer, cl_flag_update_scene);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	cl_renderer_render(gui->renderer);
}

void 				gui_signal_object_edit_plane_normal_y
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	RT_F			value;
	t_object		*object;

	gui = (t_gui *)ptr;
	if (gui->scene->edit->current_id == -1)
		return ;
	value = (RT_F)strtod(gtk_entry_get_text(GTK_ENTRY(widget)), NULL);
	object = gui->renderer->data.scene->objects +
			 gui->scene->edit->current_id;
	((t_object_plane *)object->data)->normal.y = value;
	cl_renderer_flag_set(gui->renderer, cl_flag_update_scene);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	cl_renderer_render(gui->renderer);
}

void 				gui_signal_object_edit_plane_normal_z
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	RT_F			value;
	t_object		*object;

	gui = (t_gui *)ptr;
	if (gui->scene->edit->current_id == -1)
		return ;
	value = (RT_F)strtod(gtk_entry_get_text(GTK_ENTRY(widget)), NULL);
	object = gui->renderer->data.scene->objects +
			 gui->scene->edit->current_id;
	((t_object_plane *)object->data)->normal.z = value;
	cl_renderer_flag_set(gui->renderer, cl_flag_update_scene);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	cl_renderer_render(gui->renderer);
}
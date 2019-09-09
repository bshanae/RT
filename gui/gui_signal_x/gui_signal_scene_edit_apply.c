#include "gui_signal_x.h"

void				gui_signal_scene_edit_apply
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	t_object		*object;

	gui = (t_gui *)ptr;
	object = gui->renderer->data.scene->objects + gui->scene->edit->current_id;
	gui_scene_edit_apply(gui->scene->edit, object);
	gui_control_hide(&gui->scene->edit->control);
	cl_renderer_flag_set(gui->renderer, cl_flag_update_scene);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	gui_queue_push(gui->queue);
}

#include "gui_signal_x.h"

void				gui_signal_scene_edit_apply
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui_scene_edit_background_set(gui->scene->edit,
		gui->renderer->data.scene);
	gui_scene_edit_apply(gui->scene->edit, gui->renderer->data.scene);
	scene_update(gui->renderer->data.scene);
	gui_scene_common_update_limited(gui->scene->common,
		gui->renderer->data.scene);
	gui_scene_common_update_csg(gui->scene->common,
		gui->renderer->data.scene);
	gui_control_hide(&gui->scene->edit->control);
	cl_renderer_flag_set(gui->renderer, cl_flag_update_scene);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	gui_queue_push(gui->queue);
}

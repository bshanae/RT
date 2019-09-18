#include "gui.h"

void 				gui_command_focus(t_gui *gui, GdkEventButton *event)
{
	gui->camera->focus_request = 0;
	gui_queue_block(gui->queue);
	cl_renderer_camera_request_focus(gui->renderer, event->x, event->y);
	gui_queue_execute_force(gui->queue);
	gui_queue_unblock(gui->queue);
	gui_queue_wait(gui->queue);
	gui_camera_show(gui->camera, gui->renderer->data.camera);
	gtk_widget_set_sensitive(GTK_WIDGET(gui->notebook), 1);
}

void 				gui_command_select(t_gui *gui, GdkEventButton *event)
{
	gui_queue_block(gui->queue);
	cl_renderer_camera_request_select(gui->renderer, event->x, event->y);
	gui_queue_execute_force(gui->queue);
	gui_queue_unblock(gui->queue);
	gui_queue_wait(gui->queue);
	gui_scene_edit_select(gui->scene->edit, gui->renderer->data.scene);
	gtk_widget_set_sensitive(GTK_WIDGET(gui->notebook), 1);
}

void 				gui_command_unselect(t_gui *gui)
{
	gui->renderer->data.camera->select_request_object = -1;
	scene_unselect(gui->renderer->data.scene);
	gui_scene_edit_unselect(gui->scene->edit);
	cl_renderer_flag_set(gui->renderer, cl_flag_update_camera);
	cl_renderer_flag_set(gui->renderer, cl_flag_update_scene);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	gui_queue_execute_force(gui->queue);
}

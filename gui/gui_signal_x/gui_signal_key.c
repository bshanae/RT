#include "gui_signal_x.h"

static int			try_move_camera(t_gui *gui, int key)
{
	if (key == GDK_KEY_a)
		cl_renderer_camera_move(gui->renderer, rt_movement_left);
	else if (key == GDK_KEY_d)
		cl_renderer_camera_move(gui->renderer, rt_movement_right);
	else if (key == GDK_KEY_w)
		cl_renderer_camera_move(gui->renderer, rt_movement_forward);
	else if (key == GDK_KEY_s)
		cl_renderer_camera_move(gui->renderer, rt_movement_backward);
	else if (key == GDK_KEY_q)
		cl_renderer_camera_move(gui->renderer, rt_movement_up);
	else if (key == GDK_KEY_e)
		cl_renderer_camera_move(gui->renderer, rt_movement_down);
	else
		return (0);
	gui_camera_show(gui->camera, gui->renderer->data.camera);
	gui_queue_execute_force(gui->queue);
	return (1);
}

static int			try_rotate_camera(t_gui *gui, int key)
{
	if (key == GDK_KEY_Left)
		cl_renderer_camera_rotate(gui->renderer,rt_rotation_y, rt_rotation_positive);
	else if (key == GDK_KEY_Right)
		cl_renderer_camera_rotate(gui->renderer,rt_rotation_y, rt_rotation_negative);
	else if (key == GDK_KEY_Up)
		cl_renderer_camera_rotate(gui->renderer, rt_rotation_x, rt_rotation_negative);
	else if (key == GDK_KEY_Down)
		cl_renderer_camera_rotate(gui->renderer,rt_rotation_x, rt_rotation_positive);
	else
		return (0);
	gui_camera_show(gui->camera, gui->renderer->data.camera);
	gui_queue_execute_force(gui->queue);
	return (1);
}

gboolean			gui_signal_key
					(GtkWidget *widget, GdkEventKey *event, gpointer ptr)
{
	t_gui			*gui;
	int 			image_focus;
	gboolean 		finish_condition;


	static int i;
	gui = (t_gui *)ptr;
	finish_condition = 1;
	if (event->keyval == GDK_KEY_Escape)
		gui_signal_exit(widget, ptr);
	else if (event->keyval == GDK_KEY_Return)
#ifdef RT_QUEUE_AUTO
		gui->queue->block = !gui->queue->block;
#elif defined RT_QUEUE_MANUAL
		gui_queue_execute_force(gui->queue);
#endif
	else if (event->keyval == GDK_KEY_r)
	{
		cl_renderer_camera_reset(gui->renderer);
		gui_camera_show(gui->camera, gui->renderer->data.camera);
		gui_queue_execute_force(gui->queue);
	}
	else
		finish_condition = 0;
	if (finish_condition)
		return (FALSE);
	image_focus = gtk_widget_is_focus(GTK_WIDGET(gui->image->event_box));
	if (image_focus && try_move_camera(gui, event->keyval));
	else if (image_focus && try_rotate_camera(gui, event->keyval));
	else
		return (FALSE);
	return (TRUE);
}
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
	cl_renderer_flag_set(gui->renderer, cl_flag_update_scene);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	gui_camera_show(gui->camera, gui->renderer->data.camera);
	return (1);
}

static int			try_rotate_camera(t_gui *gui, int key)
{
	if (key == GDK_KEY_Left)
		cl_renderer_camera_rotate(gui->renderer,
			rt_rotation_y, rt_rotation_positive);
	else if (key == GDK_KEY_Right)
		cl_renderer_camera_rotate(gui->renderer,
			rt_rotation_y, rt_rotation_negative);
	else if (key == GDK_KEY_Up)
		cl_renderer_camera_rotate(gui->renderer,
			rt_rotation_x, rt_rotation_negative);
	else if (key == GDK_KEY_Down)
		cl_renderer_camera_rotate(gui->renderer,
			rt_rotation_x, rt_rotation_positive);
	else
		return (0);
	cl_renderer_flag_set(gui->renderer, cl_flag_update_scene);
	cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
	gui_camera_show(gui->camera, gui->renderer->data.camera);
	return (1);
}

gboolean			gui_signal_key
					(GtkWidget *widget, GdkEventKey *key, gpointer ptr)
{
	t_gui			*gui;
	int 			image_focus;

	gui = (t_gui *)ptr;
	image_focus = gtk_widget_is_focus(GTK_WIDGET(gui->image->event_box));
	if (key->keyval == GDK_KEY_Escape)
		gui_signal_exit(widget, ptr);
	else if (image_focus && key->keyval == GDK_KEY_Return)
		cl_renderer_render(gui->renderer);
	else if (image_focus && try_move_camera(gui, key->keyval))
		cl_renderer_render(gui->renderer);
	else if (image_focus && try_rotate_camera(gui, key->keyval))
		cl_renderer_render(gui->renderer);
	else
		return (FALSE);
	return (TRUE);
}
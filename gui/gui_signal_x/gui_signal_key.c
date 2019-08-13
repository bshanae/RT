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
	gui->renderer->flags.update_camera = 1;
	cl_renderer_reset_samples(gui->renderer);
	return (1);
}

static int			try_rotate_camera(t_gui *gui, int key)
{
	if (key == GDK_KEY_leftarrow || key == GDK_KEY_j)
		cl_renderer_camera_rotate(gui->renderer,
								  rt_rotation_y, rt_rotation_positive);
	else if (key == GDK_KEY_rightarrow || key == GDK_KEY_l)
		cl_renderer_camera_rotate(gui->renderer,
								  rt_rotation_y, rt_rotation_negative);
	else if (key == GDK_KEY_uparrow || key == GDK_KEY_i)
		cl_renderer_camera_rotate(gui->renderer,
								  rt_rotation_x, rt_rotation_negative);
	else if (key == GDK_KEY_downarrow || key == GDK_KEY_k)
		cl_renderer_camera_rotate(gui->renderer,
								  rt_rotation_x, rt_rotation_positive);
	else
		return (0);
	gui->renderer->flags.update_camera = 1;
	cl_renderer_reset_samples(gui->renderer);
	return (1);
}

gboolean			gui_signal_key
					(GtkWidget *widget, GdkEventKey *key, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	if (key->keyval == GDK_KEY_Escape)
		gui_signal_exit(widget, ptr);
	else if (key->keyval == GDK_KEY_Return)
		cl_renderer_render(gui->renderer);
	else if (try_move_camera(gui, key->keyval))
		cl_renderer_render(gui->renderer);
	else if (try_rotate_camera(gui, key->keyval))
		cl_renderer_render(gui->renderer);
	return (FALSE);
}
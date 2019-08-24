#include "gui_signal_connect.h"

gboolean			task_add(gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	g_thread_pool_push(gui->pool, gui, NULL);
	return (TRUE);
}

int					i = 0;

void				task_execute(gpointer user, gpointer user_ptr)
{
	t_gui			*gui;

	gui = (t_gui *)user_ptr;
	if (g_thread_pool_unprocessed(gui->pool) > 10)
		return ;
	printf("%d : %d\n", i++, g_thread_pool_unprocessed(gui->pool));
	sleep(3);
}


void 				gui_signal_connect_all(t_gui *gui)
{
	gui->pool = g_thread_pool_new(task_execute, gui, 1, FALSE, NULL);

	g_timeout_add(200, (GSourceFunc)task_add, gui);


	RT_GUI_CONNECT(gui->builder, gui_signal_exit);
	RT_GUI_CONNECT(gui->builder, gui_signal_key);
	gui_signal_connect_camera(gui);
	gui_signal_connect_scene_edit(gui);
	gui_signal_connect_scene_add(gui);
	gui_signal_connect_settings(gui);
	gui_signal_connect_image(gui);
	gtk_builder_connect_signals(gui->builder, (gpointer)gui);
}
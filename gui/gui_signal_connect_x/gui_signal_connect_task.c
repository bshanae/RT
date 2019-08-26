#include "gui_signal_x.h"

void 				gui_signal_connect_task(t_gui *gui)
{
	gui->pool = g_thread_pool_new(gui_signal_task_execute, gui, 1, FALSE, NULL);
	g_timeout_add(100, (GSourceFunc)gui_signal_task_add, gui);
}
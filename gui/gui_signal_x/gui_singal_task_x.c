#include "gui_signal_x.h"

gboolean			gui_signal_task_add(gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	g_thread_pool_push(gui->pool, gui, NULL);
	return (TRUE);
}

int					i = 0;

void				gui_signal_task_execute(gpointer ptr, gpointer user_ptr)
{
	t_gui			*gui;

	gui = (t_gui *)user_ptr;
	if (g_thread_pool_unprocessed(gui->pool) > 10)
		return ;
	cl_renderer_render(gui->renderer);
}


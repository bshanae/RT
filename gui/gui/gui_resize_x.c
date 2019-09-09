#include "gui.h"

void				gui_resize_start(t_gui *gui)
{
	RT_ASSERT(gui->resize_in_process == rt_false)
	gui_queue_block(gui->queue);
//	gtk_window_set_resizable(gui->window, TRUE);
	gui->resize_in_process = rt_true;
}

void				gui_resize_finish(t_gui *gui)
{
	RT_ASSERT(gui->resize_in_process == rt_true)
//	gtk_window_set_resizable(gui->window, FALSE);
	g_signal_stop_emission_by_name(GTK_WIDGET(gui->window), "size_allocate");
	gui->resize_in_process = rt_false;
	gui_queue_unblock(gui->queue);
}
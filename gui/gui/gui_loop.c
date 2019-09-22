#include "gui.h"

void				gui_loop(t_gui *gui)
{
	gui_queue_start(gui->queue);
	gtk_main();
}
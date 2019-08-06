#include "gui.h"

void				gui_loop(t_gui *gui)
{
	cl_renderer_render(gui->renderer);
	gtk_main();
}
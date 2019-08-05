#include "gui.h"

void				gui_loop(t_gui *gui)
{
	renderer_frame(gui->renderer);
	gtk_main();
}
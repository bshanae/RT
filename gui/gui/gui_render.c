#include "gui.h"

void 				gui_render(t_gui *gui)
{
	cl_renderer_render(gui->renderer);
	gui_settings_show_samples(gui->settings);
}
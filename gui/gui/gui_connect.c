#include "gui.h"

void 				gui_connect(t_gui *gui)
{
	gui_camera_connect(gui->camera, gui->renderer->data.camera,
		&gui->renderer->data.settings.light_mod);
}
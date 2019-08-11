#include "gui.h"

void 				gui_load(t_gui *gui)
{
	gui_scene_edit_load(gui->scene->edit, gui->renderer->data_host.scene);
}

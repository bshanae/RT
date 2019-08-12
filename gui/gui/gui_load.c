#include "gui.h"

void 				gui_load(t_gui *gui)
{
	gui_scene_edit_update(gui->scene->edit, gui->renderer->data_host.scene);
	gui_scene_add_update(gui->scene->add);
}

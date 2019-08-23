#include "gui.h"

void 				gui_update(t_gui *gui)
{
	gui_camera_show(gui->camera, gui->renderer->data.camera);
	gui_scene_edit_update(gui->scene->edit, gui->renderer->data.scene);
	gui_scene_add_update(gui->scene->add);
	gui_settings_show(gui->settings, &gui->renderer->data.settings);
}

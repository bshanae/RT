#include "gui.h"

void 				gui_connect(t_gui *gui)
{
	gui_camera_connect(gui->camera, gui->renderer->data.camera,
		&gui->renderer->data.settings.light_mod);
	gui_scene_common_connect(gui->scene->common, gui->renderer->data.scene,
		&gui->renderer->data.settings.light_mod);
	gui_settings_connect(gui->settings, &gui->renderer->data.settings);
}
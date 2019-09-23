#include "gui.h"

void 				gui_update(t_gui *gui)
{
	gui_parser_update(gui->parser);
	gui_camera_show(gui->camera);
	gui_scene_common_update_all(gui->scene->common);
	gui_scene_edit_background_get(gui->scene->edit, gui->renderer->data.scene);
	scene_select(gui->renderer->data.scene, 0);
	gui_scene_edit_select(gui->scene->edit, gui->renderer->data.scene);
	gui_settings_show(gui->settings, &gui->renderer->data.settings);
}

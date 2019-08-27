#include "gui.h"

void				gui_delete(t_gui **gui)
{
	gui_parser_delete(&(*gui)->parser);
	gui_camera_delete(&(*gui)->camera);
	gui_scene_delete(&(*gui)->scene);
	gui_settings_delete(&(*gui)->settings);
	gui_image_delete(&(*gui)->image);
	g_thread_pool_free((*gui)->pool, TRUE, TRUE);
	cl_renderer_delete(&(*gui)->renderer);
	free(*gui);
	*gui = NULL;
}
#include "gui_scene.h"

void					gui_scene_init(t_gui_scene *gs, GtkBuilder *builder)
{
	gui_scene_list_init(gs->list, builder);
	gui_scene_params_init(gs->params, builder);
}

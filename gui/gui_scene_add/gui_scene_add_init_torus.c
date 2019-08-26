#include "gui_scene_add.h"

void 							gui_scene_add_init_torus
								(t_gui_scene_add *edit, GtkBuilder *builder)
{
	t_gui_init_torus			init;

	edit->torus = gui_object_torus_init(&init, builder);
}
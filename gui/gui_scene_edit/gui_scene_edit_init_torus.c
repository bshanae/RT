#include "gui_scene_edit.h"

void 							gui_scene_edit_init_torus
								(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_torus			init;

	edit->torus = gui_object_torus_init(&init, builder);
}
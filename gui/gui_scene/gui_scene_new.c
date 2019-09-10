#include "gui_scene.h"

t_gui_scene		*gui_scene_new(GtkBuilder *builder)
{
	t_gui_scene	*new;

	new = malloc(sizeof(t_gui_scene));
	new->common = gui_scene_common_new(builder);
	new->edit = gui_scene_edit_new(builder);
	new->add = gui_scene_add_new(builder);
	return (new);
}

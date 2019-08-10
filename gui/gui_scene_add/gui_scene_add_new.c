#include "gui_scene_add.h"

t_gui_scene_add		*gui_scene_add_new(GtkBuilder *builder)
{
	t_gui_scene_add	*new;

	new = malloc(sizeof(t_gui_scene_add));
	return (new);
}
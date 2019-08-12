#include "gui_scene_edit.h"

t_gui_scene_edit		*gui_scene_edit_new(GtkBuilder *builder)
{
	t_gui_scene_edit	*new;

	new = malloc(sizeof(t_gui_scene_edit));
	new->current_object = NULL;
	new->current_id = -1;
	new->overlay = GTK_OVERLAY(GUI_GET(builder, "scene_edit_overlay"));
	new->selection =
		GTK_TREE_SELECTION(GUI_GET(builder, "scene_edit_selection"));
	new->list = GTK_LIST_STORE(GUI_GET(builder, "scene_edit_list"));
	gui_scene_edit_set_sphere(new, builder);
	gui_scene_edit_set_plane(new, builder);
	return (new);
}
#include "gui_scene_edit.h"

t_gui_scene_edit		*gui_scene_edit_new(GtkBuilder *builder)
{
	t_gui_scene_edit	*new;

	new = malloc(sizeof(t_gui_scene_edit));
	new->overlay =
		GTK_OVERLAY(GTK_GET(builder, "scene_edit_overlay"));
	new->selection =
		GTK_TREE_SELECTION(GTK_GET(builder, "scene_edit_selection"));
	new->view =
		GTK_TREE_VIEW(GTK_GET(builder, "scene_edit_view"));
	new->list =
		GTK_LIST_STORE(GTK_GET(builder, "scene_edit_list"));
	gui_object_edit_sphere_get(&new->sphere, builder);
	gui_object_edit_universal_get((t_gui_object_edit_universal *)&new->sphere,
		new->overlay);
	gui_object_edit_plane_get(&new->plane, builder);
	gui_object_edit_universal_get((t_gui_object_edit_universal *)&new->plane,
		 new->overlay);
	new->current_box = NULL;
	new->current_id = -1;
	return (new);
}
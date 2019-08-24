#include "gui_scene_edit.h"

t_gui_scene_edit		*gui_scene_edit_new(GtkBuilder *builder)
{
	t_gui_scene_edit	*new;

	new = malloc(sizeof(t_gui_scene_edit));
	new->current_object = NULL;
	new->current_id = -1;
	new->overlay = GTK_OVERLAY(RT_GUI_GET(builder, "scene_edit_overlay"));
	new->selection =
		GTK_TREE_SELECTION(RT_GUI_GET(builder, "scene_edit_selection"));
	new->list = GTK_LIST_STORE(RT_GUI_GET(builder, "scene_edit_list"));
	new->remove_dialog =
		GTK_DIALOG(RT_GUI_GET(builder, "scene_edit_remove_dialog"));
	gui_scene_edit_set_sphere(new, builder);
	gui_scene_edit_set_plane(new, builder);
	gui_scene_edit_set_cone(new, builder);
	gui_scene_edit_set_cylinder(new, builder);
	gui_scene_edit_set_material(new, builder);
	return (new);
}
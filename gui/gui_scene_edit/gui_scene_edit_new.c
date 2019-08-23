#include "gui_scene_edit.h"

t_gui_scene_edit		*gui_scene_edit_new(GtkBuilder *builder)
{
	t_gui_scene_edit	*new;

	new = malloc(sizeof(t_gui_scene_edit));
	new->current_id = -1;
	new->stack = RT_GUI_GET(builder, "scene_edit_stack");
	new->control = RT_GUI_GET(builder, "scene_edit_control");
	new->info = RT_GUI_GET(builder, "scene_edit_info");
	new->selection = RT_GUI_GET(builder, "scene_edit_selection");
	new->list = RT_GUI_GET(builder, "scene_edit_list");
	new->remove_dialog = RT_GUI_GET(builder, "scene_edit_remove_dialog");
	new->name = RT_GUI_GET(builder, "scene_edit_name");
	new->type = RT_GUI_GET(builder, "scene_edit_type");
	gui_scene_edit_set_sphere(new, builder);
	gui_scene_edit_set_plane(new, builder);
	gui_scene_edit_set_cone(new, builder);
	gui_scene_edit_set_cylinder(new, builder);
	gui_scene_edit_set_material(new, builder);
	return (new);
}
#include "gui_scene_add.h"

t_gui_scene_add		*gui_scene_add_new(GtkBuilder *builder)
{
	t_gui_scene_add	*new;

	new = malloc(sizeof(t_gui_scene_add));
	new->current_type = object_end;
	new->gen_name_next = 0;
	new->dialog = RT_GUI_GET(builder, "dialog");
	new->name = RT_GUI_GET(builder, "scene_add_name");
	new->type_combo = RT_GUI_GET(builder, "scene_add_type_combo");
	new->type_list = RT_GUI_GET(builder, "scene_add_list");
	new->type_entry = RT_GUI_GET(builder, "scene_add_type_entry");
	new->stack = RT_GUI_GET(builder, "scene_add_stack");
	gui_scene_add_set_sphere(new, builder);
	gui_scene_add_set_plane(new, builder);
	gui_scene_add_set_cone(new, builder);
	gui_scene_add_set_cylinder(new, builder);
	gui_scene_add_set_material(new, builder);
	return (new);
}
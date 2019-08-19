#include "gui_scene_add.h"

t_gui_scene_add		*gui_scene_add_new(GtkBuilder *builder)
{
	t_gui_scene_add	*new;

	new = malloc(sizeof(t_gui_scene_add));
	new->current_object = NULL;
	new->current_type = object_end;
	new->gen_name_next = 0;
	new->dialog = GTK_DIALOG(RT_GUI_GET(builder, "dialog"));
	new->name = GTK_ENTRY(RT_GUI_GET(builder, "scene_add_name"));
	new->type_combo = GTK_COMBO_BOX(RT_GUI_GET(builder, "scene_add_type_combo"));
	new->type_list = GTK_LIST_STORE(RT_GUI_GET(builder, "scene_add_list"));
	new->type_entry = GTK_ENTRY(RT_GUI_GET(builder, "scene_add_type_entry"));
	new->overlay = GTK_OVERLAY(RT_GUI_GET(builder, "scene_add_overlay"));
	gui_scene_add_set_sphere(new, builder);
	gui_scene_add_set_plane(new, builder);
	gui_scene_add_set_cone(new, builder);
	gui_scene_add_set_ylinder(new, builder);
	gui_scene_add_set_material(new, builder);
	return (new);
}
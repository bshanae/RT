#include "gui_scene_edit.h"

t_gui_scene_edit		*gui_scene_edit_new(GtkBuilder *builder)
{
	t_gui_scene_edit	*new;

	new = malloc(sizeof(t_gui_scene_edit));
	new->overlay =
		GTK_OVERLAY(GTK_GET(builder, "scene_edit_overlay"));
	gui_object_edit_sphere_get(&new->sphere, builder);
	gui_object_edit_universal_get((t_gui_object_edit_universal *)&new->sphere,
		new->overlay);
	gtk_widget_show(GTK_WIDGET(new->sphere.box));
	return (new);
}
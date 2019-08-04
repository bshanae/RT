#include "gui/gui_object/gui_object.h"

void					gui_object_init(
						t_gui_object *go,
						GtkBuilder *builder)
{
	go->overlay =
		GTK_OVERLAY(gtk_builder_get_object(builder, GO_OVERLAY));
	gui_object_sphere_init(&go->sphere, builder, go->overlay);
}
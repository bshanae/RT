#include "gui_object_edit.h"

void 				gui_object_edit_universal_get
					(t_gui_object_edit_universal *object, GtkOverlay *onscreen)
{
	gtk_container_remove(
		GTK_CONTAINER(object->offscreen),
		GTK_WIDGET(object->box));
	gtk_overlay_add_overlay(onscreen, GTK_WIDGET(object->box));
	gtk_widget_hide(GTK_WIDGET(object->box));
}
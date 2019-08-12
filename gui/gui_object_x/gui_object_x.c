#include "gui_object_x.h"

void 				gui_object_x_set
					(t_gui_object_x *object, GtkOverlay *onscreen)
{
	gtk_container_remove(
		GTK_CONTAINER(object->offscreen),
		GTK_WIDGET(object->box));
	gtk_overlay_add_overlay(onscreen, GTK_WIDGET(object->box));
	gtk_widget_hide(GTK_WIDGET(object->box));
}

const char			*gui_object_x_get_parameter(GtkEntry *entry)
{
	const char		*str;

	str = gtk_entry_get_text(entry);
	if (!str[0])
		str = gtk_entry_get_placeholder_text(entry);
	return (str);
}
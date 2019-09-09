#include "gui_image.h"

t_gui_image			*gui_image_new(GtkBuilder *builder)
{
	t_gui_image		*new;

	printf("GUI : Initializing image\n");
	new = malloc(sizeof(t_gui_image));
	new->width = RT_GUI_WIDTH;
	new->height = RT_GUI_HEIGHT;
	new->resize_request = rt_false;
	new->event_box = GTK_EVENT_BOX(RT_GUI_GET(builder, "image_event_box"));
	gtk_widget_set_can_focus(GTK_WIDGET(new->event_box), TRUE);
	new->image = GTK_IMAGE(RT_GUI_GET(builder, "image"));
	new->gdk_buffer = NULL;
	gui_image_allocate(new);
	gtk_widget_show(GTK_WIDGET(new->image));
	return (new);
}

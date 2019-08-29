#include "gui_image.h"

static void			set_pixbuf(t_gui_image *image)
{
	image->gdk_buffer = gdk_pixbuf_new(GDK_COLORSPACE_RGB,
		TRUE, 8, image->width, image->height);
	image->char_buffer = gdk_pixbuf_get_pixels(image->gdk_buffer);
	image->color_buffer = (t_color *)image->char_buffer;
	for (int i = 0; i < image->width * image->height; i++)
		image->color_buffer[i] = (t_color){0, 0, 0, 255};
	gtk_image_set_from_pixbuf(image->image, image->gdk_buffer);
}

t_gui_image			*gui_image_new(GtkBuilder *builder)
{
	t_gui_image		*new;

	printf("GUI : Initializing image\n");
	new = malloc(sizeof(t_gui_image));
	new->width = RT_GUI_WIDTH;
	new->height = RT_GUI_HEIGHT;
	new->event_box = GTK_EVENT_BOX(RT_GUI_GET(builder, "image_event_box"));
	gtk_widget_set_can_focus(GTK_WIDGET(new->event_box), TRUE);
	new->image = GTK_IMAGE(RT_GUI_GET(builder, "image"));
	set_pixbuf(new);
	gtk_widget_show(GTK_WIDGET(new->image));
	return (new);
}

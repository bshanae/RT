#include "gui_image.h"

t_gui_image			*gui_image_new(GtkBuilder *builder)
{
	t_gui_image		*new;

	new = malloc(sizeof(t_gui_image));
	new->width = GO_DEFAULT_WIDTH;
	new->height = GO_DEFAULT_HEIGHT;
	new->image = GTK_IMAGE(gtk_builder_get_object(builder, GI_IMAGE));
	new->gdk_buffer =
		gdk_pixbuf_new(GDK_COLORSPACE_RGB, FALSE, 8, new->width, new->height);
	new->char_buffer = gdk_pixbuf_get_pixels(new->gdk_buffer);
	new->color_buffer = (t_color *)new->char_buffer;
	gtk_image_set_from_pixbuf(new->image, new->gdk_buffer);

	for (int i = 100; i < 120; i++)
		for (int j = 100; j < 120; j++)
			new->color_buffer[i * new->width + j] = (t_color){255, 255};

	return (new);
}

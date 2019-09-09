#include "gui_image.h"

void 				gui_image_allocate(t_gui_image *image)
{
	if (image->gdk_buffer)
		g_object_unref(image->gdk_buffer);
	image->gdk_buffer = gdk_pixbuf_new(GDK_COLORSPACE_RGB,
		TRUE, 8, image->width, image->height);
	image->char_buffer = gdk_pixbuf_get_pixels(image->gdk_buffer);
	image->color_buffer = (t_color *)image->char_buffer;
	for (int i = 0; i < image->width * image->height; i++)
		image->color_buffer[i] = (t_color){0, 0, 0, 255};
	gtk_image_set_from_pixbuf(image->image, image->gdk_buffer);
}
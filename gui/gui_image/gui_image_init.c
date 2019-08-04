#include "gui_image.h"

void				gui_image_init(t_gui_image *gi, GtkBuilder *builder)
{
	gi->image = GTK_IMAGE(gtk_builder_get_object(builder, GI_IMAGE));
	gi->gdk_buffer = gtk_image_get_pixbuf(gi->image);
	gi->buffer = gdk_pixbuf_get_pixels(gi->gdk_buffer);
	printf("%d\n", gdk_pixbuf_get_bits_per_sample(gi->gdk_buffer));
	gi->width = gdk_pixbuf_get_width(gi->gdk_buffer);
	printf("%d\n", gi->width);
}
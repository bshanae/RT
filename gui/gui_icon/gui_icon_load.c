#include "gui_icon.h"

void 				gui_icon_load
					(GtkBuilder *builder, CHAR_REF image_name,
	 				CHAR_REF path_to_file, t_pair_i size)
{
	GdkPixbuf		*source;
	GdkPixbuf		*scaled;
	GtkImage		*image;

	source = gdk_pixbuf_new_from_file(path_to_file, NULL);
	scaled = gdk_pixbuf_scale_simple(source,
		size.first, size.second, GDK_INTERP_HYPER);
	image = RT_GUI_GET(builder, image_name);
	gtk_image_set_from_pixbuf(image, scaled);
	gdk_pixbuf_unref(source);
	gdk_pixbuf_unref(scaled);
}
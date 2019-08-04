#ifndef GUI_IMAGE_H
# define GUI_IMAGE_H

# include "gui_names.h"

# include <gtk/gtk.h>

typedef struct 		s_gui_image
{
	GtkImage		*image;
	GdkPixbuf		*gdk_buffer;
	guchar			*buffer;
	int				width;
	int				height;
}					t_gui_image;

t_gui_image			*gui_image_new(void);
void				gui_image_init(t_gui_image *gi, GtkBuilder *builder);

#endif

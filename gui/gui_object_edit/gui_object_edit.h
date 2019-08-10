#ifndef OBJECT_EDIT_H
# define OBJECT_EDIT_H

# include <gtk/gtk.h>

# define GTK_GET	gtk_builder_get_object

typedef struct 		s_gui_object_edit_universal
{
	GtkBox			*box;
	GtkViewport		*offscreen;
}					t_gui_object_edit_universal;

void 				gui_object_edit_universal_get
					(t_gui_object_edit_universal *object,
					GtkOverlay *onscreen);

typedef struct 		s_gui_object_edit_sphere
{
	GtkBox			*box;
	GtkViewport		*offscreen;
	GtkOverlay		*onsreen;
	GtkEntry		*position_x;
	GtkEntry		*position_y;
	GtkEntry		*position_z;
	GtkEntry		*radius;
}					t_gui_object_edit_sphere;

void				gui_object_edit_sphere_get
					(t_gui_object_edit_sphere *sphere,
					GtkBuilder *builder);


#endif

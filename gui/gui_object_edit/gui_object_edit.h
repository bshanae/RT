#ifndef OBJECT_EDIT_H
# define OBJECT_EDIT_H

# include "object_definition.h"
# include "object_list.h"

# include <gtk/gtk.h>

# define GTK_GET	gtk_builder_get_object

typedef struct 		s_gui_object_edit_universal
{
	GtkBox			*box;
	GtkViewport		*offscreen;
}					t_gui_object_edit_universal;

void 				gui_object_edit_universal_get
					(t_gui_object_edit_universal *object, GtkOverlay *onscreen);

typedef struct 		s_gui_object_edit_sphere
{
	GtkBox			*box;
	GtkViewport		*offscreen;
	GtkEntry		*name;
	GtkEntry		*position_x;
	GtkEntry		*position_y;
	GtkEntry		*position_z;
	GtkEntry		*radius;
}					t_gui_object_edit_sphere;

void				gui_object_edit_sphere_get
					(t_gui_object_edit_sphere *sphere, GtkBuilder *builder);
void				gui_object_edit_sphere_load
					(t_gui_object_edit_sphere *edit, t_object *object);

typedef struct 		s_gui_object_edit_plane
{
	GtkBox			*box;
	GtkViewport		*offscreen;
	GtkEntry		*name;
	GtkEntry		*position_x;
	GtkEntry		*position_y;
	GtkEntry		*position_z;
	GtkEntry		*normal_x;
	GtkEntry		*normal_y;
	GtkEntry		*normal_z;
}					t_gui_object_edit_plane;

void				gui_object_edit_plane_get
					(t_gui_object_edit_plane *plane, GtkBuilder *builder);
void 				gui_object_edit_plane_load
					(t_gui_object_edit_plane *edit, t_object *object);

#endif

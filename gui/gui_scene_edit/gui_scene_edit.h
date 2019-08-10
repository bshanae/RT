#ifndef GUI_OBJECT_EDIT_H
# define GUI_OBJECT_EDIT_H

# include "gui_object_edit.h"

# include <gtk/gtk.h>

# define GTK_GET				gtk_builder_get_object

typedef struct 					s_gui_scene_edit
{
	t_gui_object_edit_sphere	sphere;
	GtkOverlay					*overlay;
}								t_gui_scene_edit;

t_gui_scene_edit				*gui_scene_edit_new
								(GtkBuilder *builder);
void 							gui_scene_edit_delete
								(t_gui_scene_edit **object);

#endif

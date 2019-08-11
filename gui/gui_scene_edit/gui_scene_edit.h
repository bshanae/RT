#ifndef GUI_OBJECT_EDIT_H
# define GUI_OBJECT_EDIT_H

# include "gui_object_edit.h"
# include "scene.h"

# include <gtk/gtk.h>

# define GTK_GET				gtk_builder_get_object

typedef enum 					s_gui_scene_edit_column
{
	scene_edit_object_id,
	scene_edit_object_name,
	scene_edit_type_icon,
	scene_edit_type_id
}								t_gui_scene_edit_column;

typedef struct 					s_gui_scene_edit
{
	t_gui_object_edit_sphere	sphere;
	t_gui_object_edit_plane		plane;
	GtkOverlay					*overlay;
	GtkTreeView					*view;
	GtkListStore				*list;
	GtkTreeSelection			*selection;
	int 						current_id;
	GtkBox						*current_box;
}								t_gui_scene_edit;

t_gui_scene_edit				*gui_scene_edit_new
								(GtkBuilder *builder);
void 							gui_scene_edit_delete
								(t_gui_scene_edit **object);

void							gui_scene_edit_gen_name
								(t_object *object);
void 							gui_scene_edit_load
								(t_gui_scene_edit *edit, t_scene *scene);

#endif

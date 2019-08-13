#ifndef GUI_OBJECT_EDIT_H
# define GUI_OBJECT_EDIT_H

# include "rt_float.h"

# include "gui_object_x.h"
# include "scene.h"

# include <gtk/gtk.h>

typedef enum 					s_gui_scene_edit_list
{
	scene_edit_object_id,
	scene_edit_object_name,
	scene_edit_type_icon,
	scene_edit_type_id
}								t_gui_scene_edit_list;

typedef struct 					s_gui_scene_edit
{
	t_gui_object_sphere			sphere;
	t_gui_object_plane			plane;
	GtkOverlay					*overlay;
	GtkListStore				*list;
	GtkTreeSelection			*selection;
	int 						current_id;
	GtkBox						*current_object;
	GtkTreeIter					iter;
	GtkDialog					*remove_dialog;
}								t_gui_scene_edit;

t_gui_scene_edit				*gui_scene_edit_new
								(GtkBuilder *builder);
void 							gui_scene_edit_delete
								(t_gui_scene_edit **object);

void 							gui_scene_edit_set_sphere
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void 							gui_scene_edit_set_plane
								(t_gui_scene_edit *edit, GtkBuilder *builder);

void							gui_scene_edit_gen_name
								(t_object *object);
void 							gui_scene_edit_update
								(t_gui_scene_edit *edit, t_scene *scene);
void 							gui_scene_edit_show
								(t_gui_scene_edit *edit, t_object *object);
GtkBox							*gui_scene_edit_get_object
								(t_gui_scene_edit *edit, t_object_type type);

#endif

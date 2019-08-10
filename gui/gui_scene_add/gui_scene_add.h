#ifndef GUI_OBJECT_ADD_H
# define GUI_OBJECT_ADD_H

# include <gtk/gtk.h>

typedef struct 		s_gui_scene_add
{

}					t_gui_scene_add;

t_gui_scene_add		*gui_scene_add_new(GtkBuilder *builder);
void 				gui_scene_add_delete(t_gui_scene_add **object);

#endif

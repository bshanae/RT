#ifndef GUI_SCENE_LIST_H
# define GUI_SCENE_LIST_H

# include "gui_names.h"

# include <gtk/gtk.h>

typedef struct			s_gui_scene_list
{
	GtkListStore		*data;
	GtkTreeView			*view;
	GtkTreeSelection	*select;
}						t_gui_scene_list;

t_gui_scene_list		*gui_scene_list_new(void);
void					gui_scene_list_delete(t_gui_scene_list **gsl);

void					gui_scene_list_init(
						t_gui_scene_list *gsl,
						GtkBuilder *builder);

#endif

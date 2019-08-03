#ifndef GUI_SCENE
# define GUI_SCENE

# include "gui_scene_list.h"
# include "gui_scene_params.h"

# include <gtk/gtk.h>

typedef	struct			s_gui_scene
{
	t_gui_scene_list	*list;
	t_gui_scene_params	*params;
}						t_gui_scene;

t_gui_scene				*gui_scene_new(void);
void					gui_scene_delete(t_gui_scene **gs);

void					gui_scene_init(t_gui_scene *gs, GtkBuilder *builder);

#endif

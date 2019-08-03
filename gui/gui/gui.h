#ifndef GUI_H
# define GUI_H

# include "gui_names.h"

# include "gui_scene.h"

# include <gtk/gtk.h>

typedef struct		s_gui
{
	GtkBuilder		*builder;
	GtkWindow		*window;
	t_gui_scene		*scene;
}					t_gui;

t_gui				*gui_new(void);
void				gui_delete(t_gui **gui);

void				gui_init(t_gui *gui, int *ac, char ***av);
void				gui_start(t_gui *gui);
void				gui_finish(t_gui *gui);

#endif

#ifndef GUI_H
# define GUI_H

# include "rt_parameters.h"

# include "gui_camera.h"
# include "gui_scene.h"
# include "gui_settings.h"
# include "gui_image.h"
# include "cl_renderer.h"

# include <gtk/gtk.h>

typedef struct		s_gui
{
	GtkCssProvider	*css_provider;
	GtkBuilder		*builder;
	GtkWindow		*window;
	GThreadPool		*pool;
	GtkEntry		*notebook_fix[3];
	t_gui_camera	*camera;
	t_gui_scene		*scene;
	t_gui_settings	*settings;
	t_gui_image		*image;
	t_cl_renderer	*renderer;
}					t_gui;

t_gui				*gui_new(int *ac, char ***av);
void				gui_delete(t_gui **gui);

void				gui_loop(t_gui *gui);
void 				gui_update(t_gui *gui);

#endif

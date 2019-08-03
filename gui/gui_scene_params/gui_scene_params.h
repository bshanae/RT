#ifndef GUI_SCENE_LIST_PARAMS_H
# define GUI_SCENE_LIST_PARAMS_H

# include "gui_names.h"

# include <gtk/gtk.h>

typedef struct			s_gui_scene_param
{
	GtkBox				*param;
	GtkViewport			*offscreen_parent;
}						t_gui_scene_param;

typedef struct			s_gui_scene_params
{
	t_gui_scene_param	sphere;
	t_gui_scene_param	plane;
	GtkWidget			*current;
	GtkOverlay			*overlay;
}						t_gui_scene_params;

t_gui_scene_params		*gui_scene_params_new(void);
void					gui_scene_params_delete(t_gui_scene_params **gsp);

void					gui_scene_param_init(
						t_gui_scene_param *gsp,
						GtkBuilder *builder,
						const char *param_name,
						const char *parent_name);

void					gui_scene_params_init(
						t_gui_scene_params *gsp,
						GtkBuilder *builder);

#endif

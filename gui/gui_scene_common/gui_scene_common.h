#ifndef GUI_SCENE_COMMON_H
# define GUI_SCENE_COMMON_H

# include "rt_parameters.h"

# include "scene.h"

# include <gtk/gtk.h>

typedef struct 		s_gui_scene_common
{
	GtkListStore	*full;
	GtkListStore	*limited_main;
	GtkListStore	*limited_limit;
	GtkListStore	*csg;
	GtkListStore	*types;
	t_rt_bool		reset_generator;
}					t_gui_scene_common;

t_gui_scene_common	*gui_scene_common_new(GtkBuilder *builder);
void				gui_scene_common_delete(t_gui_scene_common **common);

typedef enum 		s_gui_scene_list_column
{
	gui_scene_column_id,
	gui_scene_column_name,
}					t_gui_scene_list_column;

void				gui_scene_common_gen_name
					(t_gui_scene_common *scene, t_object *object);

t_rt_bool			gui_scene_common_func_a
					(int rm_mod, t_object *object);
void				gui_scene_common_func_b
					(GtkListStore *list, t_object *object);

void 				gui_scene_common_update_full
					(t_gui_scene_common *gui, t_scene *scene, int rm_mod);
void				gui_scene_common_update_limited
					(t_gui_scene_common *gui, t_scene *scene);
void				gui_scene_common_update_csg
					(t_gui_scene_common *gui, t_scene *scene);
void 				gui_scene_common_update_all
					(t_gui_scene_common *gui, t_scene *scene, int rm_mod);

#endif

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
	GtkListStore	*textures;
	t_rt_bool		reset_generator;
}					t_gui_scene_common;

t_gui_scene_common	*gui_scene_common_new(GtkBuilder *builder);
void				gui_scene_common_delete(t_gui_scene_common **common);

typedef enum 		s_gui_scene_objects_column
{
	gui_objects_column_id,
	gui_objects_column_name
}					t_gui_scene_objects_column;

typedef enum 		s_gui_scene_types_column
{
	gui_types_column_name,
	gui_types_column_id
}					t_gui_scene_types_column;

typedef enum 		s_gui_scene_textures_column
{
	gui_textures_column_name,
	gui_textures_column_id
}					t_gui_scene_textures_column;

void				gui_scene_common_gen_name
					(t_gui_scene_common *scene, t_object *object);

void				gui_scene_common_add_to_list
					(GtkListStore *list, t_object *object);

void 				gui_scene_common_update_full
					(t_gui_scene_common *gui, t_scene *scene);
void				gui_scene_common_update_limited
					(t_gui_scene_common *gui, t_scene *scene);
void				gui_scene_common_update_csg
					(t_gui_scene_common *gui, t_scene *scene);
void 				gui_scene_common_update_types
					(t_gui_scene_common *gui, t_scene *scene);
void 				gui_scene_common_update_textures
					(t_gui_scene_common *gui, t_scene *scene);
void 				gui_scene_common_update_all
					(t_gui_scene_common *gui, t_scene *scene);

#endif

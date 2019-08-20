#ifndef GUI_OBJECT_ADD_H
# define GUI_OBJECT_ADD_H

# include "rt_parameters.h"

# include "libft_standart.h"
# include "object_definition.h"
# include "gui_material.h"
# include "gui_object_x.h"

# include <gtk/gtk.h>

typedef enum 				e_gui_scene_add_list
{
	scene_add_type_name,
	scene_add_type_id
}							t_gui_scene_add_list;

typedef struct 				s_gui_scene_add
{
	GtkDialog				*dialog;
	GtkEntry				*name;
	GtkComboBox				*type_combo;
	GtkEntry				*type_entry;
	GtkListStore			*type_list;
	GtkOverlay				*overlay;
	t_gui_object_sphere		sphere;
	t_gui_object_plane		plane;
	t_gui_object_cone		cone;
	t_gui_object_cylinder	cylinder;
	t_gui_material			material;
	GtkBox					*current_object;
	t_object_type			current_type;
	int 					gen_name_next;
}							t_gui_scene_add;

t_gui_scene_add				*gui_scene_add_new(GtkBuilder *builder);
void 						gui_scene_add_delete(t_gui_scene_add **object);

void 						gui_scene_add_set_sphere
							(t_gui_scene_add *add, GtkBuilder *builder);
void 						gui_scene_add_set_plane
							(t_gui_scene_add *add, GtkBuilder *builder);
void 						gui_scene_add_set_cone
							(t_gui_scene_add *add, GtkBuilder *builder);
void 						gui_scene_add_set_cylinder
							(t_gui_scene_add *add, GtkBuilder *builder);
void						gui_scene_add_set_material
							(t_gui_scene_add *add, GtkBuilder *builder);

void 						gui_scene_add_update
							(t_gui_scene_add *add);
GtkBox						*gui_scene_add_get_object(t_gui_scene_add *add);
void 						gui_scene_add_show(t_gui_scene_add *add);
char						*gui_scene_add_gen_name(t_gui_scene_add *add);
void						gui_scene_add_build_object
							(t_gui_scene_add *add, t_object *space);

#endif

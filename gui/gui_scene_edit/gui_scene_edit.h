#ifndef GUI_OBJECT_EDIT_H
# define GUI_OBJECT_EDIT_H

# include "rt_float.h"

# include "gui_object_x.h"
# include "gui_material.h"
# include "gui_control.h"
# include "gui_scene_common.h"
# include "scene.h"

# include <gtk/gtk.h>

typedef struct 					s_gui_scene_edit
{
	t_gui_scene_common			*common;
	t_gui_control				control;
	GtkEntry					*name;
	GtkEntry					*type;
	t_gui_object_light_point	light_point;
	t_gui_object_light_direct	light_direct;
	t_gui_object_sphere			sphere;
	t_gui_object_plane			plane;
	t_gui_object_cone			cone;
	t_gui_object_cylinder		cylinder;
	t_gui_object_box			box;
	t_gui_object_paraboloid		paraboloid;
	t_gui_object_moebius		moebius;
	t_gui_object_torus			torus;
	t_gui_object_mandelbulb		mandelbulb;
	t_gui_object_julia			julia;
	GtkWidget					*material_color_box;
	int 						material_color_silent;
	t_gui_material				material;
	GtkStack					*stack;
	GtkBox						*info;
	GtkTreeSelection			*selection;
	int 						current_id;
	GtkTreeIter					iter;
	GtkDialog					*remove_dialog;
}								t_gui_scene_edit;

t_gui_scene_edit				*gui_scene_edit_new
								(GtkBuilder *builder);
void 							gui_scene_edit_delete
								(t_gui_scene_edit **object);

void 							gui_scene_edit_init_own
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void 							gui_scene_edit_init_light_point
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void 							gui_scene_edit_init_light_direct
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void 							gui_scene_edit_init_sphere
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void 							gui_scene_edit_init_plane
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void 							gui_scene_edit_init_cone
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void 							gui_scene_edit_init_cylinder
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void 							gui_scene_edit_init_box
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void 							gui_scene_edit_init_paraboloid
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void 							gui_scene_edit_init_moebius
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void 							gui_scene_edit_init_torus
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void 							gui_scene_edit_init_mandelbulb
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void 							gui_scene_edit_init_julia
								(t_gui_scene_edit *edit, GtkBuilder *builder);
void 							gui_scene_edit_init_material
								(t_gui_scene_edit *edit, GtkBuilder *builder);

void 							gui_scene_edit_show
								(t_gui_scene_edit *edit, t_object *object);
void							gui_scene_edit_apply
								(t_gui_scene_edit *edit, t_object* object);
void 							gui_scene_edit_material_color_enable
								(t_gui_scene_edit *edit);
void 							gui_scene_edit_material_color_disable
								(t_gui_scene_edit *edit);

#endif

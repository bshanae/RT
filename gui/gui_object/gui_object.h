#ifndef GUI_OBJECT_H
# define GUI_OBJECT_H

# include "gui_object_base.h"
# include "object_definition.h"
# include "object_data.h"

# include <stdio.h>

typedef struct			s_gui_object_sphere
{
	t_gui_object_base	base;
	GtkEntry			*position_x;
	GtkEntry			*position_y;
	GtkEntry			*position_z;
}						t_gui_object_sphere;

void 					gui_object_sphere_init
						(t_gui_object_sphere *sphere,
		 				GtkBuilder *builder,
						 GtkOverlay *target);

typedef struct			s_gui_object
{
	t_gui_object_sphere	sphere;
	GtkWidget			*current_widget;
	int 				current_id;
	GtkOverlay			*overlay;
}						t_gui_object;

t_gui_object			*gui_object_new(void);
void					gui_scene_object_delete(t_gui_object **gsp);

void					gui_object_init
						(t_gui_object *gsp, GtkBuilder *builder);
void					gui_sphere_load
						(t_gui_object_sphere *gui, t_object *sphere);



#endif

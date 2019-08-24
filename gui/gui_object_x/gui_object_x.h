#ifndef GUI_OBJECT_X_H
# define GUI_OBJECT_X_H

# include "libft_standart.h"
# include "gui_entry.h"
# include "f4.h"
# include "object_definition.h"
# include "object_x.h"

# include <gtk/gtk.h>

typedef struct 			s_gui_init_sphere
{
	char				box[64];
	char				position_x[64];
	char				position_y[64];
	char				position_z[64];
	char				radius[64];
}						t_gui_init_sphere;

typedef struct 			s_gui_object_sphere
{
	GtkBox				*box;
	GtkEntry			*position_x;
	GtkEntry			*position_y;
	GtkEntry			*position_z;
	GtkEntry			*radius;
}						t_gui_object_sphere;

t_gui_object_sphere		gui_object_sphere_set
						(t_gui_init_sphere *init, GtkBuilder *builder);
void					gui_object_sphere_show
						(t_gui_object_sphere *gui, t_object *object);
void 					gui_object_sphere_build
						(t_gui_object_sphere *gui, t_object *object);

typedef struct 			s_gui_init_plane
{
	char				box[64];
	char				position_x[64];
	char				position_y[64];
	char				position_z[64];
	char				normal_x[64];
	char				normal_y[64];
	char				normal_z[64];
}						t_gui_init_plane;

typedef struct 			s_gui_object_plane
{
	GtkBox				*box;
	GtkEntry			*position_x;
	GtkEntry			*position_y;
	GtkEntry			*position_z;
	GtkEntry			*normal_x;
	GtkEntry			*normal_y;
	GtkEntry			*normal_z;
}						t_gui_object_plane;

t_gui_object_plane		gui_object_plane_set
						(t_gui_init_plane *init, GtkBuilder *builder);
void 					gui_object_plane_show
						(t_gui_object_plane *gui, t_object *object);
void 					gui_object_plane_build
						(t_gui_object_plane *gui, t_object *object);

typedef struct			s_gui_init_cone
{
	char				box[64];
	char				top_x[64];
	char				top_y[64];
	char				top_z[64];
	char				bottom_x[64];
	char				bottom_y[64];
	char				bottom_z[64];
	char				radius[64];
}						t_gui_init_cone;

typedef struct			s_gui_object_cone
{
	GtkBox				*box;
	GtkEntry			*top_x;
	GtkEntry			*top_y;
	GtkEntry			*top_z;
	GtkEntry			*bottom_x;
	GtkEntry			*bottom_y;
	GtkEntry			*bottom_z;
	GtkEntry			*radius;
}						t_gui_object_cone;

t_gui_object_cone		gui_object_cone_set
						(t_gui_init_cone *init, GtkBuilder *builder);
void 					gui_object_cone_show
						(t_gui_object_cone *gui, t_object *object);
void 					gui_object_cone_build
						(t_gui_object_cone *gui, t_object *object);

typedef struct			s_gui_init_cylinder
{
	char				box[64];
	char				top_x[64];
	char				top_y[64];
	char				top_z[64];
	char				bottom_x[64];
	char				bottom_y[64];
	char				bottom_z[64];
	char				radius[64];
}						t_gui_init_cylinder;

typedef struct			s_gui_object_cylinder
{
	GtkBox				*box;
	GtkEntry			*top_x;
	GtkEntry			*top_y;
	GtkEntry			*top_z;
	GtkEntry			*bottom_x;
	GtkEntry			*bottom_y;
	GtkEntry			*bottom_z;
	GtkEntry			*radius;
}						t_gui_object_cylinder;

t_gui_object_cylinder	gui_object_cylinder_set
						(t_gui_init_cylinder *init, GtkBuilder *builder);
void 					gui_object_cylinder_show
						(t_gui_object_cylinder *gui, t_object *object);
void 					gui_object_cylinder_build
						(t_gui_object_cylinder *gui, t_object *object);

#endif

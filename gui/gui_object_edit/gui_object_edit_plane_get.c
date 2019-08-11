#include "gui_object_edit.h"

void				gui_object_edit_plane_get
					(t_gui_object_edit_plane *plane,
					GtkBuilder *builder)
{
	plane->box = GTK_BOX(GTK_GET(builder, "object_edit_plane_box"));
	plane->offscreen =
		GTK_VIEWPORT(GTK_GET(builder, "object_edit_plane_offscreen"));
	plane->name =
		GTK_ENTRY(GTK_GET(builder, "object_edit_plane_name"));
	plane->position_x =
		GTK_ENTRY(GTK_GET(builder, "object_edit_plane_position_x"));
	plane->position_y =
		GTK_ENTRY(GTK_GET(builder, "object_edit_plane_position_y"));
	plane->position_z =
		GTK_ENTRY(GTK_GET(builder, "object_edit_plane_position_z"));
	plane->normal_x =
		GTK_ENTRY(GTK_GET(builder, "object_edit_plane_normal_x"));
	plane->normal_y =
		GTK_ENTRY(GTK_GET(builder, "object_edit_plane_normal_y"));
	plane->normal_z =
		GTK_ENTRY(GTK_GET(builder, "object_edit_plane_normal_z"));
}
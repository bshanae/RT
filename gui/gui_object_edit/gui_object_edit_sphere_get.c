#include "gui_object_edit.h"

void 				gui_object_edit_sphere_get
					(t_gui_object_edit_sphere *sphere,
					GtkBuilder *builder)
{
	sphere->box = GTK_BOX(GTK_GET(builder, "object_edit_sphere_box"));
	sphere->offscreen =
		GTK_VIEWPORT(GTK_GET(builder, "object_edit_sphere_offscreen"));
	sphere->position_x =
		GTK_ENTRY(GTK_GET(builder, "object_edit_sphere_position_x"));
	sphere->position_y =
		GTK_ENTRY(GTK_GET(builder, "object_edit_sphere_position_y"));
	sphere->position_z =
		GTK_ENTRY(GTK_GET(builder, "object_edit_sphere_position_z"));
	sphere->radius =
		GTK_ENTRY(GTK_GET(builder, "object_edit_sphere_radius"));
}

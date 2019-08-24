#include "gui_scene_add.h"

void 				gui_scene_add_show(t_gui_scene_add *add)
{
	if (add->current_type == object_sphere)
		gui_object_sphere_show(&add->sphere, NULL);
	else if (add->current_type == object_plane)
		gui_object_plane_show(&add->plane, NULL);
	else if (add->current_type == object_cone)
		gui_object_cone_show(&add->cone, NULL);
	else if (add->current_type == object_cylinder)
		gui_object_cylinder_show(&add->cylinder, NULL);
	else
		return ;
	gtk_widget_show(GTK_WIDGET(add->current_object));
}

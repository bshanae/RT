#include "gui_scene_edit.h"

void 				gui_scene_edit_show
					(t_gui_scene_edit *edit, t_object *object)
{
	if (object->type == object_sphere)
		gui_object_sphere_show(&edit->sphere, object);
	else if (object->type == object_plane)
		gui_object_plane_show(&edit->plane, object);
	else
		return ;
	gtk_widget_show(GTK_WIDGET(edit->current_object));
}
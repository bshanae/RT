#include "gui_scene_edit.h"

void 				gui_scene_edit_show
					(t_gui_scene_edit *edit, t_object *object)
{
	if (object->type == object_sphere)
		gui_object_sphere_show(&edit->sphere, object);
	else if (object->type == object_plane)
		gui_object_plane_show(&edit->plane, object);
	else if (object->type == object_cone)
		gui_object_cone_show(&edit->cone, object);
	else if (object->type == object_cylinder)
		gui_object_cylinder_show(&edit->cylinder, object);
	else
		return ;
	gui_material_show(&edit->material, &object->material);
	gtk_widget_show(GTK_WIDGET(edit->current_object));
}
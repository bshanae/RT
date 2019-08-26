#include "gui_scene_add.h"

void				gui_scene_add_build_object
					(t_gui_scene_add *add, t_object *object)
{
	if (!gtk_entry_get_text(add->name)[0])
		add->gen_name_next++;
	ft_strcpy(object->name, gui_entry_get_str(add->name));
	object->type = add->current_type;
	if (object->type == object_light_point)
		gui_object_light_point_set(&add->light_point, object);
	else if (object->type == object_light_direct)
		gui_object_light_direct_set(&add->light_direct, object);
	else if (object->type == object_sphere)
		gui_object_sphere_set(&add->sphere, object);
	else if (object->type == object_plane)
		gui_object_plane_set(&add->plane, object);
	else if (object->type == object_cone)
		gui_object_cone_set(&add->cone, object);
	else if (object->type == object_cylinder)
		gui_object_cylinder_set(&add->cylinder, object);
	else if (object->type == object_box)
		gui_object_box_set(&add->box, object);
	else if (object->type == object_paraboloid)
		gui_object_paraboloid_set(&add->paraboloid, object);
	else if (object->type == object_moebius)
		gui_object_moebius_set(&add->moebius, object);
	else if (object->type == object_torus)
		gui_object_torus_set(&add->torus, object);
	else if (object->type == object_mandelbulb)
		gui_object_mandelbulb_set(&add->mandelbulb, object);
	else if (object->type == object_julia)
		gui_object_julia_set(&add->julia, object);
	gui_material_set(&add->material, &object->material);
}
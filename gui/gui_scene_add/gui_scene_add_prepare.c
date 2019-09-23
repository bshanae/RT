#include "gui_scene_add.h"

void				static_default_object(t_object *object)
{
	object->type = object_type_sphere;
	object->material = MATERIAL_WHITE;
	object->texture_id = -1;
}

void 				gui_scene_add_prepare(t_gui_scene_add *add)
{
	CHAR_REF		str;
	GtkTreeIter		iter;

	str = gui_scene_add_gen_name(add);
	gtk_entry_set_placeholder_text(add->name, str);
	free((void *)str);
	static_default_object(&add->temp_object);
	gui_material_prepare(&add->material, &add->temp_object);
	gui_material_get(&add->material, &add->temp_object.material,
		&add->temp_object.texture_id);
	gtk_tree_model_get_iter_first(GTK_TREE_MODEL(add->common->types), &iter);
	gtk_combo_box_set_active(add->type_combo, object_type_sphere);
}
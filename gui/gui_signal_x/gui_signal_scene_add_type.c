#include "gui_signal_x.h"

void 				gui_signal_scene_add_type
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	GtkTreeIter		iter;

	gui = (t_gui *)ptr;
	if (!gtk_combo_box_get_active_iter(gui->scene->add->type_combo, &iter))
		return ;
	gtk_tree_model_get(GTK_TREE_MODEL(gui->scene->add->type_list), &iter,
		scene_add_type_id, &gui->scene->add->current_type, -1);
	gtk_stack_set_visible_child_name(gui->scene->add->stack,
		 object_translate(gui->scene->add->current_type));
	if (gui->scene->add->current_type >= object_light_ambient &&
		gui->scene->add->current_type <= object_light_direct)
		gui_scene_add_material_state_light(gui->scene->add);
	else
		gui_scene_add_material_state_non_light(gui->scene->add);
}

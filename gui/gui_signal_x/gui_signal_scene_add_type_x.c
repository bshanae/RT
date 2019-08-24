#include "gui_signal_x.h"

void 				gui_signal_scene_add_type_auto
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	GtkTreeIter		iter;

	gui = (t_gui *)ptr;
	if (!gtk_combo_box_get_active_iter(gui->scene->add->type_combo, &iter))
		return ;
	gtk_tree_model_get(GTK_TREE_MODEL(gui->scene->add->type_list), &iter,
		scene_add_type_id, &gui->scene->add->current_type, -1);
		gui_scene_add_get_object(gui->scene->add);
	gui_scene_add_show(gui->scene->add);
}

void 				gui_signal_scene_add_type_manual
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	const char		*str;
	t_object_type	type;

	gui = (t_gui *)ptr;
	str = gtk_entry_get_text(GTK_ENTRY(widget));
	type = 0;
	while (type < object_end)
	{
		if (!ft_strcmp(str, object_translate(type)))
			break ;
		type++;
	}
	if (type == object_end)
		return;
	gui->scene->add->current_type = type;
	gui_scene_add_show(gui->scene->add);
}
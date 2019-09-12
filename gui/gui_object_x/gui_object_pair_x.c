#include "gui_object_x.h"


t_gui_object_pair			gui_object_pair_init
							(t_gui_init_pair *init, GtkBuilder *builder)
{
	t_gui_object_pair		pair;

	pair.first_combo = RT_GUI_GET(builder, init->first_combo);
	pair.first_list = RT_GUI_GET(builder, init->first_list);
	gtk_combo_box_set_model(pair.first_combo, GTK_TREE_MODEL(pair.first_list));
	pair.second_combo = RT_GUI_GET(builder, init->second_combo);
	pair.second_list = RT_GUI_GET(builder, init->second_list);
	gtk_combo_box_set_model(pair.second_combo, GTK_TREE_MODEL(pair.second_list));
	return (pair);
}

void						gui_object_pair_get
	(t_gui_object_pair *gui, t_object *object)
{

}

void 						gui_object_pair_set
	(t_gui_object_pair *gui, t_object *object)
{

}
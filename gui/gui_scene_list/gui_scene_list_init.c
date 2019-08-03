#include "gui_scene_list.h"

void					gui_scene_list_init(
						t_gui_scene_list *gsl,
						GtkBuilder *builder)
{
	gsl->data = GTK_LIST_STORE(gtk_builder_get_object(builder, GSL_DATA));
	gsl->view = GTK_TREE_VIEW(gtk_builder_get_object(builder, GSL_VIEW));
	gsl->select =
		GTK_TREE_SELECTION(gtk_builder_get_object(builder, GSL_SELECT));
}
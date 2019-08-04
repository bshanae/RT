#include "gui_list.h"

void					gui_list_init(
						t_gui_list *gl,
						GtkBuilder *builder)
{
	gl->data = GTK_LIST_STORE(gtk_builder_get_object(builder, GL_DATA));
	gl->view = GTK_TREE_VIEW(gtk_builder_get_object(builder, GL_VIEW));
	gl->select =
		GTK_TREE_SELECTION(gtk_builder_get_object(builder, GL_SELECT));
}
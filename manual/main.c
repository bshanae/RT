#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK(statement) if (!statement) printf("Error on line %d\n", __LINE__);

typedef struct			s_gtk_list
{
	GtkTreeView			*view;
	GtkTreeSelection	*select;
	GtkListStore		*list;		
}						t_gtk_list;

typedef struct			s_gtk_data
{
	GtkBuilder			*builder;
	GtkWindow			*window;
	t_gtk_list			list;
	GtkEntry			*entry;
}						t_gtk_data;

void					foo(t_gtk_data *data);

int						main(int argc, char **argv)
{
	t_gtk_data			data;

	gtk_init(&argc, &argv);

	data.builder = GTK_BUILDER(gtk_builder_new_from_file("build_3.glade"));
	data.window = GTK_WINDOW(gtk_builder_get_object(data.builder, "main_window"));
	data.list.view = GTK_TREE_VIEW(gtk_builder_get_object(data.builder, "view_1"));
	data.list.list = GTK_LIST_STORE(gtk_builder_get_object(data.builder, "list_1"));
	data.list.select = GTK_TREE_SELECTION(gtk_builder_get_object(data.builder, "view_1_select"));

	gtk_builder_connect_signals(data.builder, NULL);

	foo(&data);

	gtk_widget_show_all(GTK_WIDGET(data.window));

	gtk_main();

	return (0);
}


void				foo(t_gtk_data *data)
{
	gchar			str[2];
	GtkTreeIter		iter;

	str[1] = '\0';
	for (int i = 0; i < 10; i++)
	{
		str[0] = 'a' + i;
		gtk_list_store_append(data->list.list, &iter);
		gtk_list_store_set(data->list.list, &iter, 0, str, -1);
	}

}

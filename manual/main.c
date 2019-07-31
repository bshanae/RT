#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK(statement) if (!statement) printf("Error on line %d\n", __LINE__);

typedef struct			s_gtk_list
{
	GtkTreeView			*view;
	GtkTreeSelection	*select;
	GtkListStore		*list;
	GtkTreeIter			iter;
	int					iter_is_set;
}						t_gtk_list;

typedef struct			s_gtk_data
{
	GtkBuilder			*builder;
	GtkWindow			*window;
	t_gtk_list			list;
	GtkEntry			*entry;
}						t_gtk_data;

void					foo(t_gtk_data *data);
void					list_1_selected(GtkTreeSelection *, gpointer);
void					list_1_edited_name(GtkEntry *, gpointer);


int						main(int argc, char **argv)
{
	t_gtk_data			data;

	gtk_init(&argc, &argv);

	data.builder = GTK_BUILDER(gtk_builder_new_from_file("build_3.glade"));
	data.window = GTK_WINDOW(gtk_builder_get_object(data.builder, "main_window"));
	data.list.view = GTK_TREE_VIEW(gtk_builder_get_object(data.builder, "view_1"));
	data.list.list = GTK_LIST_STORE(gtk_builder_get_object(data.builder, "list_1"));
	data.list.select = GTK_TREE_SELECTION(gtk_builder_get_object(data.builder, "view_1_select"));
	data.list.iter_is_set = 0;
	data.entry = GTK_ENTRY(gtk_builder_get_object(data.builder, "entry_1"));
	if (!data.entry)
		return (1);

	gtk_builder_connect_signals(data.builder, NULL);

	g_signal_connect(data.list.select, "changed", G_CALLBACK(list_1_selected), (gpointer)&data);
	g_signal_connect(data.entry, "activate", G_CALLBACK(list_1_edited_name), (gpointer)&data);

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

void				list_1_selected(GtkTreeSelection *select, gpointer ptr)
{
	t_gtk_data		*data;
	GtkTreeModel	*model;
	gchar			*value;

	data = (t_gtk_data *)ptr;
	gtk_tree_selection_get_selected(select, &model, &data->list.iter);
	gtk_tree_model_get(model, &data->list.iter, 0, &value, -1);
	gtk_entry_set_text(data->entry, value);
	data->list.iter_is_set = 1;
}

void				list_1_edited_name(GtkEntry *entry, gpointer ptr)
{
	t_gtk_data		*data;
	const gchar		*text;

	data = (t_gtk_data *)ptr;
	text = gtk_entry_get_text(entry);
	if (data->list.iter_is_set && text[0])
		gtk_list_store_set(data->list.list, &data->list.iter, 0, text, -1);

}


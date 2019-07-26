#include "libft_ft_printf.h"

#include <gtk/gtk.h>

void				func_clean(GtkWidget *widget, gpointer ptr)
{
	gtk_entry_set_text(GTK_ENTRY(ptr), "");
}

void				func_write(GtkWidget *widget, gpointer ptr)
{
	g_print("%s\n", gtk_entry_get_text(GTK_ENTRY(ptr)));
}

int					main(int argc, char **argv)
{
	GtkWidget		*window;
	GtkWidget		*table;
	GtkWidget		*entry;
	GtkWidget		*button_clean;
	GtkWidget		*button_write;


	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	table = gtk_table_new(2, 2, 1);
	entry = gtk_entry_new();
	button_clean = gtk_button_new_with_label("clean");
	button_write = gtk_button_new_with_label("write");

	gtk_widget_set_size_request(window, 480, 360);
	gtk_window_set_title(GTK_WINDOW(window), "Window");

	gtk_table_attach(GTK_TABLE(table), entry, 0, 2, 0, 1, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach(GTK_TABLE(table), button_clean, 0, 1, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
	gtk_table_attach(GTK_TABLE(table), button_write, 1, 2, 1, 2, GTK_FILL, GTK_FILL, 0, 0);

	gtk_container_add(GTK_CONTAINER(window), table);

	gtk_widget_show_all(window);

	g_signal_connect(window, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(button_clean, "clicked", G_CALLBACK(func_clean), (gpointer)entry);
	g_signal_connect(button_write, "clicked", G_CALLBACK(func_write), (gpointer)entry);

	gtk_main();

	return (0);
}
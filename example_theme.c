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
	GtkCssProvider *css_provider;
	GtkWidget		*window;
	GtkWidget		*box_big;
	GtkWidget		*box_little;
	GtkWidget		*entry;
	GtkWidget		*button_clean;
	GtkWidget		*button_write;


	gtk_init(&argc, &argv);

	css_provider = gtk_css_provider_new();
	gtk_css_provider_load_from_path(css_provider, "/Users/vladimir/workspace/21_ray_tracer/Adwaita/gtk-dark.css", NULL);
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
											  GTK_STYLE_PROVIDER(css_provider),
											  GTK_STYLE_PROVIDER_PRIORITY_USER);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	box_big = gtk_vbox_new(TRUE, 0);
	box_little = gtk_hbox_new(TRUE, 10);

	entry = gtk_entry_new();

	button_clean = gtk_button_new_with_label("clean");
	button_write = gtk_button_new_with_label("write");

	gtk_widget_set_size_request(window, 480, 360);
	gtk_window_set_title(GTK_WINDOW(window), "Window");

	gtk_box_pack_start(GTK_BOX(box_little), button_clean, TRUE, TRUE, FALSE);
	gtk_box_pack_start(GTK_BOX(box_little), button_write, TRUE, TRUE, FALSE);

	gtk_box_pack_start(GTK_BOX(box_big), entry, TRUE, TRUE, TRUE);
	gtk_box_pack_start(GTK_BOX(box_big), box_little, TRUE, TRUE, TRUE);

	gtk_container_add(GTK_CONTAINER(window), box_big);

	gtk_widget_show_all(window);

	g_signal_connect(window, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(button_clean, "clicked", G_CALLBACK(func_clean), (gpointer)entry);
	g_signal_connect(button_write, "clicked", G_CALLBACK(func_write), (gpointer)entry);

	gtk_main();

	return (0);
}
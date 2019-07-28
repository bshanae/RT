#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK(statement) if (!statement) printf("Error on line %d\n", __LINE__);

void				toggle_button_1_interaction(GtkWidget *widget, gpointer ptr)
{
	if (gtk_toggle_button_get_active(widget))
		gtk_label_set_text (GTK_LABEL(ptr), (const gchar* )"on");
	else
		gtk_label_set_text (GTK_LABEL(ptr), (const gchar* )"off");
}

int					main(int argc, char **argv)
{
	GtkBuilder		*builder;
	GtkWidget		*window;
	GtkWidget		*button;
	GtkWidget		*label;

	gtk_init(&argc, &argv);

	builder = gtk_builder_new_from_file("build_2.glade");
	CHECK(builder)

	window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
	CHECK(window)
	button = GTK_WIDGET(gtk_builder_get_object(builder, "toggle_button_1"));
	label = GTK_WIDGET(gtk_builder_get_object(builder, "label_1"));

	gtk_builder_connect_signals(builder, NULL);

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_widget_show(window);

	gtk_main();

	return (0);
}

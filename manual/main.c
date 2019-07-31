#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK(statement) if (!statement) printf("Error on line %d\n", __LINE__);

int					main(int argc, char **argv)
{
	GtkWidget		*window;
	GtkBuilder		*builder;

	gtk_init(&argc, &argv);

	builder = gtk_builder_new_from_file("build_3.glade");

	window = GTK_WIDGET(gtk_builder_get_object(builder, "window_0"));

	gtk_builder_connect_signals(builder, NULL);

	gtk_widget_show_all(window);

	gtk_main();

	return (0);
}

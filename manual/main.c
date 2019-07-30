#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK(statement) if (!statement) printf("Error on line %d\n", __LINE__);

typedef struct		s_window
{
	GtkBuilder		*builder;
	GtkWidget		*window_0;
	GtkWidget		*stack_0;
}					t_window;

int					main(int argc, char **argv)
{
	t_window		window;

	gtk_init(&argc, &argv);

	window.builder = gtk_builder_new_from_file("build_2.glade");

	window.window_0 = GTK_WIDGET(gtk_builder_get_object(window.builder, "window_0"));
	window.stack_0 = GTK_WIDGET(gtk_builder_get_object(window.builder, "stack_0"));

	gtk_builder_connect_signals(window.builder, NULL);

	gtk_widget_show_all(window.window_0);

	gtk_main();

	return (0);
}

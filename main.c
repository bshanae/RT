#include "libft_ft_printf.h"

#include <gtk/gtk.h>
#include <math.h>

float				progress_value = 0.f;

gboolean			unclick(gpointer ptr)
{
	if (progress_value > 0. && progress_value < 1.)
		progress_value -= progress_value * sinf(progress_value * M_PI) / 5.;
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(ptr), progress_value);
	return (TRUE);
}

void				click(GtkWidget *widget, gpointer ptr)
{
	if (progress_value < 1.)
		progress_value += 0.05;
	else
		gtk_button_set_label(GTK_BUTTON(widget), "you are amazing!");
	gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(ptr), progress_value);
}

int					main(int argc, char **argv)
{
	GtkWidget		*window;
	GtkWidget		*box;
	GtkWidget		*progress;
	GtkWidget		*button;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	box = gtk_vbox_new(TRUE, 10);

	progress = gtk_progress_bar_new();

	button = gtk_button_new_with_label("click!");

	gtk_widget_set_size_request(window, 480, 360);
	gtk_window_set_title(GTK_WINDOW(window), "Window");

	gtk_box_pack_start(GTK_BOX(box), progress, TRUE, TRUE, FALSE);
	gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, FALSE);

	gtk_container_add(GTK_CONTAINER(window), box);

	gtk_widget_show_all(window);

	g_timeout_add(400, unclick, (gpointer)progress);

	g_signal_connect(window, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(button, "clicked", G_CALLBACK(click), (gpointer)progress);

	gtk_main();

	return (0);
}
#include "libft_ft_printf.h"

#include <gtk/gtk.h>

int 				x = 0;
char				prefix[] = "you clicked ";
char 				postfix[] = " times";

void 				make_string(char **target)
{
	char			*number;
	int 			number_length;

	number = ft_itoa(++x);
	number_length = ft_strlen(number);
	(*target) = (char *)malloc(ft_strlen(prefix) + ft_strlen(postfix) + number_length + 1);
	int i = 0;
	for (; prefix[i]; i++)
		(*target)[i] = prefix[i];
	for (int j = 0; j < number_length; j++)
		(*target)[i++] = number[j];
	for (int j = 0; postfix[j]; j++)
		(*target)[i++] = postfix[j];
	(*target)[i] = '\0';
	printf("target : %s\n", *target);
}

void				button_event(GtkWidget *widget, gpointer ptr)
{
	char 			*result;

	make_string(&result);
	gtk_label_set_text(GTK_LABEL(ptr), result);
	free(result);
}

int					main(int argc, char **argv)
{
	GtkWidget		*window;
	GtkWidget		*box_v;
	GtkWidget		*button;
	GtkWidget		*label;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	box_v = gtk_vbox_new(0,10);
	button = gtk_button_new_with_label("button");
	label  = gtk_label_new("you clicked 0 times");

	gtk_widget_set_size_request(window, 480, 360);
	gtk_window_set_title(GTK_WINDOW(window), "You expected a name, but it was me! Dio!");

	gtk_box_pack_start(GTK_BOX(box_v), label, 1, 1, 0);
	gtk_box_pack_start(GTK_BOX(box_v), button, 1, 1, 0);

	gtk_container_add(GTK_CONTAINER(window), box_v);

	gtk_widget_show_all(window);

	g_signal_connect(window, "delete_event", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect(button, "clicked", G_CALLBACK(button_event), (gpointer)label);

	gtk_main();

	return (0);
}
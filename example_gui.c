#include <gtk/gtk.h>

typedef struct
{
	GtkBox					*sphere;
	GtkViewport				*sphere_offscreen;
	GtkBox					*plane;
	GtkViewport				*plane_offscreen;
	GtkOverlay				*overlay;
	GtkWidget				*current;
}							t_gui_overlay;

typedef struct
{
	GtkListStore			*data;
	GtkTreeView				*view;
	GtkTreeSelection		*select;
}							t_gui_list;

typedef struct
{
	GtkBuilder				*builder;
	GtkWindow				*window;
	t_gui_overlay			overlay;
	t_gui_list				list;
}							t_gui;

void						gui_list_append(t_gui_list *list)
{

}

int							main(int argc, char **argv)
{
	t_gui					gui;

	gtk_init(&argc, &argv);

	gui.builder = gtk_builder_new_from_file("build_4.glade");
	gui.window = GTK_WINDOW(gtk_builder_get_object(gui.builder, "window"));

	{
		gui.overlay.sphere = GTK_BOX(gtk_builder_get_object(gui.builder, "sphere_box"));
		gui.overlay.sphere_offscreen = GTK_VIEWPORT(gtk_builder_get_object(gui.builder, "sphere_offscreen"));

		gui.overlay.plane = GTK_BOX(gtk_builder_get_object(gui.builder, "plane_box"));
		gui.overlay.plane_offscreen = GTK_VIEWPORT(gtk_builder_get_object(gui.builder, "plane_offscreen"));

		gui.overlay.overlay = GTK_OVERLAY(gtk_builder_get_object(gui.builder, "overlay"));

		gtk_container_remove(GTK_CONTAINER(gui.overlay.sphere_offscreen), GTK_WIDGET(gui.overlay.sphere));
		gtk_container_remove(GTK_CONTAINER(gui.overlay.plane_offscreen), GTK_WIDGET(gui.overlay.plane));

		gtk_overlay_add_overlay(gui.overlay.overlay, GTK_WIDGET(gui.overlay.sphere)); 
		gtk_overlay_add_overlay(gui.overlay.overlay, GTK_WIDGET(gui.overlay.plane));

		gui.overlay.current = GTK_WIDGET(gui.overlay.sphere); 
	}


	{
		gui.list.data = GTK_LIST_STORE(gtk_builder_get_object(gui.builder, "list"));
		gui.list.view = GTK_TREE_VIEW(gtk_builder_get_object(gui.builder, "tree"));
		gui.list.select = GTK_TREE_SELECTION(gtk_builder_get_object(gui.builder, "select"));
	}

	gtk_builder_connect_signals(gui.builder, (gpointer)&gui);

	gtk_widget_show(GTK_WIDGET(gui.window));

	gtk_main();

	return (0);
}

void						change_object(GtkButton *button, gpointer ptr)
{
	t_gui					*gui;

	gui = (t_gui *)ptr;
	gtk_widget_hide(gui->overlay.current);
	if (gui->overlay.current == GTK_WIDGET(gui->overlay.sphere))
		gui->overlay.current = GTK_WIDGET(gui->overlay.plane);
	else
		gui->overlay.current = GTK_WIDGET(gui->overlay.sphere);
	gtk_widget_show(gui->overlay.current);
}

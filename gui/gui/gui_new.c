#include "gui.h"

t_gui				*gui_new(int *ac, char ***av)
{
	t_gui			*new;

	gtk_disable_setlocale();
	gtk_init(ac, av);
	new = (t_gui *)malloc(sizeof(t_gui));
	new->css_provider = gtk_css_provider_new();
	gtk_css_provider_load_from_path(new->css_provider, RT_GUI_THEME, NULL);
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
		GTK_STYLE_PROVIDER(new->css_provider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);
	new->builder = gtk_builder_new_from_file(RT_GUI_BUILD);
	new->window = GTK_WINDOW(RT_GUI_GET(new->builder, "window"));
	new->camera = gui_camera_new(new->builder);
	new->scene = gui_scene_new(new->builder);
	new->settings = gui_settings_new(new->builder);
	new->image = gui_image_new(new->builder);
	new->renderer = cl_renderer_new(new->image);
	gui_camera_show(new->camera, new->renderer->data_host.camera);
	gtk_widget_grab_focus(GTK_WIDGET(new->image->event_box));
	gtk_widget_show(GTK_WIDGET(new->window));
	return (new);
}
#include "gui.h"

void 				gui_css(t_gui *gui)
{
	gui->css_provider = gtk_css_provider_new();
	gtk_css_provider_load_from_path(gui->css_provider, RT_GUI_THEME, NULL);
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
		GTK_STYLE_PROVIDER(gui->css_provider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);
}

t_gui				*gui_new(int *ac, char ***av)
{
	t_gui			*new;

	gtk_disable_setlocale();
	gtk_init(ac, av);
	new = (t_gui *)malloc(sizeof(t_gui));
	gui_css(new);
	new->builder = gtk_builder_new_from_file(RT_GUI_BUILD);
	new->window = RT_GUI_GET(new->builder, "window");
	new->notebook_fix[0] = RT_GUI_GET(new->builder, "notebook_fix_0");
	new->notebook_fix[1] = RT_GUI_GET(new->builder, "notebook_fix_1");
	new->notebook_fix[2] = RT_GUI_GET(new->builder, "notebook_fix_2");
	new->camera = gui_camera_new(new->builder);
	new->scene = gui_scene_new(new->builder);
	new->settings = gui_settings_new(new->builder);
	new->image = gui_image_new(new->builder);
	new->renderer = cl_renderer_new(new->image);
	gtk_widget_show(GTK_WIDGET(new->window));
	gtk_widget_grab_focus(GTK_WIDGET(new->image->event_box));
	return (new);
}
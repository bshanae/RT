#include "gui.h"

void 				static_load_theme(t_gui *gui)
{
	gui->css_provider = gtk_css_provider_new();
	gtk_css_provider_load_from_path(gui->css_provider, RT_SOURCE_GUI_THEME, NULL);
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
		GTK_STYLE_PROVIDER(gui->css_provider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);
}

t_gui				*gui_new(int *ac, char ***av)
{
	t_gui			*new;

	gtk_disable_setlocale();
	gtk_init(ac, av);
	new = (t_gui *)rt_malloc(sizeof(t_gui));
	static_load_theme(new);
	new->builder = gtk_builder_new_from_file(RT_SOURCE_GUI_BUILD);
	new->window = RT_GUI_GET(new->builder, "window");
	gtk_window_set_resizable(new->window, FALSE);
	new->notebook= RT_GUI_GET(new->builder, "notebook");
	new->notebook_page[0] = RT_GUI_GET(new->builder, "notebook_page_parser");
	new->notebook_page[1] = RT_GUI_GET(new->builder, "notebook_page_camera");
	new->notebook_page[2] = RT_GUI_GET(new->builder, "notebook_page_scene");
	new->notebook_page[3] = RT_GUI_GET(new->builder, "notebook_page_settings");
	new->queue = gui_queue_new(new, (void (*)(void *))gui_render);
	gui_icon_load_all(new->builder);
	new->parser = gui_parser_new(new->builder);
	new->camera = gui_camera_new(new->builder);
	new->scene = gui_scene_new(new->builder);
	new->settings = gui_settings_new(new->builder);
	new->notebook_control[0] = NULL;
	new->notebook_control[1] = &new->camera->control;
	new->notebook_control[2] = &new->scene->edit->control;
	new->notebook_control[3] = &new->settings->control;
	new->image = gui_image_new(new->builder);
	new->resize_in_process = rt_false;
	gtk_widget_show(GTK_WIDGET(new->window));
	gtk_widget_grab_focus(GTK_WIDGET(new->image->event_box));
	printf("GUI : Ready\n\n");


	return (new);
}
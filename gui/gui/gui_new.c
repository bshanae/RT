/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:24:55 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

static void			static_load_theme(t_gui *gui)
{
	gui->css_provider = gtk_css_provider_new();
	gtk_css_provider_load_from_path(gui->css_provider,
		RT_SOURCE_GUI_THEME, NULL);
	gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
		GTK_STYLE_PROVIDER(gui->css_provider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);
}

static void			static_load_notebook(t_gui *gui)
{
	gui->notebook = RT_GUI_GET(gui->builder, "notebook");
	gui->notebook_page[0] = RT_GUI_GET(gui->builder, "notebook_page_parser");
	gui->notebook_page[1] = RT_GUI_GET(gui->builder, "notebook_page_camera");
	gui->notebook_page[2] = RT_GUI_GET(gui->builder, "notebook_page_scene");
	gui->notebook_page[3] = RT_GUI_GET(gui->builder, "notebook_page_settings");
}

static void			static_load_control(t_gui *gui)
{
	gui->notebook_control[0] = NULL;
	gui->notebook_control[1] = &gui->camera->control;
	gui->notebook_control[2] = &gui->scene->edit->control;
	gui->notebook_control[3] = &gui->settings->control;
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
	gtk_window_set_title(new->window, RT_GUI_TITLE);
	static_load_notebook(new);
	new->queue = gui_queue_new(new, (void (*)(void *))gui_render);
	gui_icon_load_all(new->builder);
	new->parser = gui_parser_new(new->builder);
	new->camera = gui_camera_new(new->builder);
	new->scene = gui_scene_new(new->builder);
	new->settings = gui_settings_new(new->builder);
	static_load_control(new);
	new->image = gui_image_new(new->builder);
	new->resize_in_process = rt_false;
	gtk_widget_show(GTK_WIDGET(new->window));
	gtk_widget_grab_focus(GTK_WIDGET(new->image->event_box));
	printf("GUI : Ready\n\n");
	return (new);
}

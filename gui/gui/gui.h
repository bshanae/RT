/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:15:31 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_H
# define GUI_H

# include "rt_parameters.h"
# include "rt_sources_gui.h"

# include "gui_queue.h"
# include "gui_icon.h"
# include "gui_parser.h"
# include "gui_camera.h"
# include "gui_scene.h"
# include "gui_settings.h"
# include "gui_image.h"
# include "cl_renderer.h"

# include <gtk/gtk.h>

typedef enum		e_gui_notebook_page
{
	gui_notebook_parser,
	gui_notebook_camera,
	gui_notebook_scene,
	gui_notebook_settings,
	gui_notebook_end
}					t_gui_notebook_page;

typedef struct		s_gui
{
	GtkCssProvider	*css_provider;
	GtkBuilder		*builder;
	GtkWindow		*window;
	GtkNotebook		*notebook;
	GtkWidget		*notebook_page[4];
	t_gui_control	*notebook_control[4];
	t_gui_queue		*queue;
	t_gui_parser	*parser;
	t_gui_camera	*camera;
	t_gui_scene		*scene;
	t_gui_settings	*settings;
	t_gui_image		*image;
	t_rt_bool		resize_in_process;
	t_cl_renderer	*renderer;
}					t_gui;

t_gui				*gui_new(int *ac, char ***av);
void				gui_delete(t_gui **gui);

void				gui_resize_start(t_gui *gui);
void				gui_resize_finish(t_gui *gui);

void				gui_loop(t_gui *gui);
void				gui_update(t_gui *gui);
void				gui_connect(t_gui *gui);
void				gui_render(t_gui *gui);

void				gui_command_focus(t_gui *gui, GdkEventButton *event);
void				gui_command_select(t_gui *gui, GdkEventButton *event);
void				gui_command_unselect(t_gui *gui);
void				gui_command_move(t_gui *gui, t_rt_movement movement);

#endif

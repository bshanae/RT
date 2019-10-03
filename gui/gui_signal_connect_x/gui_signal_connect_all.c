/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_connect_all.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:22:09 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:22:11 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_connect_x.h"

void				gui_signal_connect_all(t_gui *gui)
{
	RT_GUI_CONNECT(gui, gui_signal_exit);
	RT_GUI_CONNECT(gui, gui_signal_key);
	gui_signal_connect_entry(gui);
	gui_signal_connect_parser(gui);
	gui_signal_connect_camera(gui);
	gui_signal_connect_scene_edit(gui);
	gui_signal_connect_scene_add(gui);
	gui_signal_connect_settings(gui);
	gui_signal_connect_image(gui);
	gtk_builder_connect_signals(gui->builder, (gpointer)gui);
	printf("GUI Signal: Ready\n\n");
}

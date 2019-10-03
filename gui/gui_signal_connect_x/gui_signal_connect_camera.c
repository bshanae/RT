/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_connect_camera.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:22:27 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:22:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_connect_x.h"

void				gui_signal_connect_camera(t_gui *gui)
{
	printf("GUI Signal: Connecting camera callbacks\n");
	RT_GUI_CONNECT(gui, gui_signal_camera_state_reset);
	RT_GUI_CONNECT(gui, gui_signal_camera_state_save);
	RT_GUI_CONNECT(gui, gui_signal_camera_state_dialog_response);
	RT_GUI_CONNECT(gui, gui_signal_camera_antialiasing);
	RT_GUI_CONNECT(gui, gui_signal_camera_filter);
	RT_GUI_CONNECT(gui, gui_signal_camera_focus_state);
	RT_GUI_CONNECT(gui, gui_signal_camera_focus_auto);
	RT_GUI_CONNECT(gui, gui_signal_camera_screen_save);
	RT_GUI_CONNECT(gui, gui_signal_camera_screen_dialog_response);
	RT_GUI_CONNECT(gui, gui_signal_camera_apply);
	RT_GUI_CONNECT(gui, gui_signal_camera_reset);
}

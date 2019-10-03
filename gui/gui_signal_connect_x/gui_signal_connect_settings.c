/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_connect_settings.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:23:56 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:23:56 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_connect_x.h"

void				gui_signal_connect_settings(t_gui *gui)
{
	printf("GUI Signal: Connecting settings callbacks\n");
	RT_GUI_CONNECT(gui, gui_signal_settings_reset);
	RT_GUI_CONNECT(gui, gui_signal_settings_apply);
	RT_GUI_CONNECT(gui, gui_signal_settings_resize);
	RT_GUI_CONNECT(gui, gui_signal_settings_tracing_rt);
	RT_GUI_CONNECT(gui, gui_signal_settings_tracing_rm);
	RT_GUI_CONNECT(gui, gui_signal_settings_light);
	RT_GUI_CONNECT(gui, gui_signal_settings_illumination_state);
	RT_GUI_CONNECT(gui, gui_signal_settings_motion_blur);
}

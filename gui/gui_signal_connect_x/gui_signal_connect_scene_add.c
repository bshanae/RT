/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_connect_scene_add.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:23:30 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:23:30 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_connect_x.h"

void				gui_signal_connect_scene_add(t_gui *gui)
{
	printf("GUI Signal: Connecting object creator callbacks\n");
	RT_GUI_CONNECT(gui, gui_signal_scene_add_response_cancel);
	RT_GUI_CONNECT(gui, gui_signal_scene_add_response_yes);
	RT_GUI_CONNECT(gui, gui_signal_scene_add_response_no);
	RT_GUI_CONNECT(gui, gui_signal_scene_add_block_destroy);
	RT_GUI_CONNECT(gui, gui_signal_scene_add_type_select);
	RT_GUI_CONNECT(gui, gui_signal_scene_add_switch_material);
	RT_GUI_CONNECT(gui, gui_signal_scene_add_switch_texture);
	RT_GUI_CONNECT(gui, gui_signal_scene_add_material_color);
	RT_GUI_CONNECT(gui, gui_signal_scene_add_material_emission);
}

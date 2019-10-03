/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_connect_scene_edit.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:23:43 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:23:43 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_connect_x.h"

void				gui_signal_connect_scene_edit(t_gui *gui)
{
	printf("GUI Signal: Connecting object editor callbacks\n");
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_select);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_combo_changed);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_reset);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_apply);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_switch_material);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_switch_texture);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_material_color);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_material_emission);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_scale_changed);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_add);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_remove);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_remove_response_cancel);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_remove_response_yes);
	RT_GUI_CONNECT(gui, gui_signal_scene_edit_remove_response_no);
}

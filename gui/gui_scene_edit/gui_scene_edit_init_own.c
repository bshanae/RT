/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_edit_init_own.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:14:55 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_edit.h"

void					gui_scene_edit_init_own
	(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_control	init;

	edit->common = NULL;
	edit->background_combo = RT_GUI_GET(builder, "scene_edit_background_combo");
	edit->stack = RT_GUI_GET(builder, "scene_edit_stack");
	ft_strcpy(init.stack, "scene_edit_control");
	edit->control = gui_control_init(&init, builder);
	edit->info = RT_GUI_GET(builder, "scene_edit_info");
	edit->selection = RT_GUI_GET(builder, "scene_edit_selection");
	edit->selection_silent = rt_false;
	edit->remove_button = RT_GUI_GET(builder, "scene_edit_remove_button");
	edit->remove_dialog = RT_GUI_GET(builder, "scene_edit_remove_dialog");
	edit->name = RT_GUI_GET(builder, "scene_edit_name");
	edit->type = RT_GUI_GET(builder, "scene_edit_type");
}

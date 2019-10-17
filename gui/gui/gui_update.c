/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:26:00 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void				gui_update(t_gui *gui)
{
	gui_parser_update(gui->parser);
	gui_camera_show(gui->camera);
	gui_scene_common_update_all_wrapped(gui->scene->common);
	gui_scene_edit_background_get(gui->scene->edit, gui->renderer->data.scene);
	gui_settings_show(gui->settings);
}

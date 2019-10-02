/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_connect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:20:02 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:20:02 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void				gui_connect(t_gui *gui)
{
	gui_camera_connect(gui->camera, gui->renderer->data.camera,
		&gui->renderer->data.settings.light_mod);
	gui_scene_common_connect(gui->scene->common, gui->renderer->data.scene,
		&gui->renderer->data.settings.light_mod);
	gui_settings_connect(gui->settings, &gui->renderer->data.settings);
}

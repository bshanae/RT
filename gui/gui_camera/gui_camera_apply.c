/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_camera_apply.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:27:23 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:27:23 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_camera.h"

void				gui_camera_apply(t_gui_camera *gui)
{
	t_camera		*camera;

	rt_assert_critical(gui->connected, "GUI Camera : Not connected");
	camera = gui->ptr_camera;
	camera->position.x = gui_entry_get_f(gui->position_x);
	camera->position.y = gui_entry_get_f(gui->position_y);
	camera->position.z = gui_entry_get_f(gui->position_z);
	camera->rotation.x = gui_entry_get_f(gui->rotation_x);
	camera->rotation.y = gui_entry_get_f(gui->rotation_y);
	camera->rotation.z = gui_entry_get_f(gui->rotation_z);
	camera->focal_length = gui_entry_get_f(gui->focus_focal_length);
	camera->aperture_size = gui_entry_get_f(gui->focus_aperture_size);
	camera_apply(camera);
}

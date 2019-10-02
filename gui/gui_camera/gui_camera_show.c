/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_camera_show.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:31:38 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:31:38 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_camera.h"

static void			static_set_filter(t_gui_camera *gui, t_camera *camera)
{
	if (*gui->ptr_light == rt_light_basic)
		gtk_widget_set_sensitive(gui->filter_cartoon_box, 1);
	else
	{
		if (gui->ptr_camera->filter_mod == rt_filter_cartoon)
			gui->ptr_camera->filter_mod = rt_filter_none;
		gtk_toggle_button_set_active(gui->filter_cartoon, 0);
		gtk_widget_set_sensitive(gui->filter_cartoon_box, 0);
	}
	gtk_toggle_button_set_active(gui->filter_none,
		camera->filter_mod == rt_filter_none);
	gtk_toggle_button_set_active(gui->filter_cartoon,
		camera->filter_mod == rt_filter_cartoon);
	gtk_toggle_button_set_active(gui->filter_sepia,
		camera->filter_mod == rt_filter_sepia);
	gtk_toggle_button_set_active(gui->filter_stereo,
		camera->filter_mod == rt_filter_stereo);
}

void				gui_camera_show(t_gui_camera *gui)
{
	t_camera		*camera;

	rt_assert_critical(gui->connected, "GUI Camera : Not connected");
	camera = gui->ptr_camera;
	gui->control.silent = rt_true;
	gui_entry_set_f(gui->position_x, camera->position.x);
	gui_entry_set_f(gui->position_y, camera->position.y);
	gui_entry_set_f(gui->position_z, camera->position.z);
	gui_entry_set_f(gui->rotation_x, camera->rotation.x);
	gui_entry_set_f(gui->rotation_y, camera->rotation.y);
	gui_entry_set_f(gui->rotation_z, camera->rotation.z);
	gtk_switch_set_state(gui->antialiasing, camera->filter_antialiasing);
	static_set_filter(gui, camera);
	gtk_switch_set_state(gui->focus, camera->focus);
	gtk_widget_set_sensitive(GTK_WIDGET(gui->focus_box), camera->focus);
	gui_entry_set_f(gui->focus_focal_length, camera->focal_length);
	gui_entry_set_f(gui->focus_aperture_size, camera->aperture_size);
	gui->control.silent = rt_false;
}

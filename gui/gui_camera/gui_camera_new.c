/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_camera_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:30:25 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:30:25 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_camera.h"

static void				static_init_a(t_gui_camera *camera, GtkBuilder *builder)
{
	t_gui_init_control	init;

	camera->connected = rt_false;
	camera->ptr_camera = NULL;
	camera->ptr_light = NULL;
	ft_strcpy(init.stack, "camera_control");
	camera->control = gui_control_init(&init, builder);
	camera->position_x = RT_GUI_GET(builder, "camera_position_x");
	camera->position_y = RT_GUI_GET(builder, "camera_position_y");
	camera->position_z = RT_GUI_GET(builder, "camera_position_z");
	camera->rotation_x = RT_GUI_GET(builder, "camera_rotation_x");
	camera->rotation_y = RT_GUI_GET(builder, "camera_rotation_y");
	camera->rotation_z = RT_GUI_GET(builder, "camera_rotation_z");
	camera->state_dialog = RT_GUI_GET(builder, "camera_state_dialog");
	camera->state_label = RT_GUI_GET(builder, "camera_state_label");
}

static void				static_init_b(t_gui_camera *camera, GtkBuilder *builder)
{
	camera->screen_dialog = RT_GUI_GET(builder, "camera_screen_dialog");
	camera->screen_label = RT_GUI_GET(builder, "camera_screen_label");
	camera->antialiasing = RT_GUI_GET(builder, "camera_antialiasing");
	camera->filter_none = RT_GUI_GET(builder, "camera_filter_none");
	camera->filter_cartoon_box = RT_GUI_GET(builder,
			"camera_filter_cartoon_box");
	camera->filter_cartoon = RT_GUI_GET(builder, "camera_filter_cartoon");
	camera->filter_sepia = RT_GUI_GET(builder, "camera_filter_sepia");
	camera->filter_stereo = RT_GUI_GET(builder, "camera_filter_stereo");
	camera->focus = RT_GUI_GET(builder, "camera_focus");
	camera->focus_request = 0;
	camera->focus_box = RT_GUI_GET(builder, "camera_focus_box");
	camera->focus_focal_length = RT_GUI_GET(builder,
			"camera_focus_focal_length");
	camera->focus_aperture_size =
			RT_GUI_GET(builder, "camera_focus_aperture_size");
}

t_gui_camera			*gui_camera_new(GtkBuilder *builder)
{
	t_gui_camera		*new;

	printf("GUI : Initializing camera\n");
	new = rt_malloc(sizeof(t_gui_camera));
	static_init_a(new, builder);
	static_init_b(new, builder);
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_settings_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:01:34 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 17:03:04 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_settings.h"

static void				static_init
	(t_gui_settings *settings, GtkBuilder *builder)
{
	settings->tracing_block = rt_false;
	settings->tracing_rt = RT_GUI_GET(builder, "settings_tracing_rt");
	settings->tracing_rm = RT_GUI_GET(builder, "settings_tracing_rm");
	settings->stack = RT_GUI_GET(builder, "settings_stack");
	settings->rm_steps = RT_GUI_GET(builder, "settings_rm_steps");
	settings->rm_part = RT_GUI_GET(builder, "settings_rm_part");
	settings->rm_distance = RT_GUI_GET(builder, "settings_rm_distance");
	settings->illumination_state =
		RT_GUI_GET(builder, "settings_illumination_state");
	settings->illumination_value =
		RT_GUI_GET(builder, "settings_illumination_value");
	settings->light_basic = RT_GUI_GET(builder, "settings_light_basic");
	settings->light_area = RT_GUI_GET(builder, "settings_light_area");
	settings->pt_samples_number =
		RT_GUI_GET(builder, "settings_pt_samples_number");
	settings->pt_samples_limit =
		RT_GUI_GET(builder, "settings_pt_samples_limit");
	settings->pt_depth = RT_GUI_GET(builder, "settings_pt_depth");
	settings->motion_blur = RT_GUI_GET(builder, "settings_motion_blur");
}

t_gui_settings			*gui_settings_new(GtkBuilder *builder)
{
	t_gui_settings		*new;
	t_gui_init_control	init;

	printf("GUI : Initializing settings\n");
	new = rt_malloc(sizeof(t_gui_settings));
	new->connected = rt_false;
	ft_strcpy(init.stack, "settings_control");
	new->control = gui_control_init(&init, builder);
	static_init(new, builder);
	return (new);
}

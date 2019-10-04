/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_settings_show.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:03:39 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 17:04:54 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_settings.h"

void					gui_settings_show_samples(t_gui_settings *gui)
{
	rt_assert_critical(gui->connected, "GUI Settings : Not connected");
	gui_entry_set_i(gui->pt_samples_number,
		gui->ptr_settings->sample_count - 1);
}

void					gui_settings_show(t_gui_settings *gui)
{
	t_rt_tracing_mod	mod;

	rt_assert_critical(gui->connected, "GUI Settings : Not connected");
	mod = gui->ptr_settings->tracing_mod;
	gui->tracing_block = rt_true;
	gtk_toggle_button_set_active(gui->tracing_rt, mod == rt_tracing_rt);
	gtk_toggle_button_set_active(gui->tracing_rm, mod == rt_tracing_rm);
	gui->tracing_block = rt_false;
	gtk_stack_set_visible_child_name(gui->stack,
		mod == rt_tracing_rt ? "rt" : "rm");
	gui_entry_set_i(gui->rm_steps, gui->ptr_settings->rm_step_limit);
	gui_entry_set_f(gui->rm_part, gui->ptr_settings->rm_step_part);
	gui_entry_set_f(gui->rm_distance, gui->ptr_settings->rm_max_distance);
	gtk_toggle_button_set_active(gui->light_basic,
		gui->ptr_settings->light_mod == rt_light_basic);
	gtk_toggle_button_set_active(gui->light_area,
		gui->ptr_settings->light_mod == rt_light_area);
	gtk_switch_set_active(gui->illumination_state,
		gui->ptr_settings->illumination);
	gui_entry_set_f(gui->illumination_value,
		gui->ptr_settings->illumination_value);
	gui_entry_set_i(gui->pt_samples_limit, gui->ptr_settings->sample_limit);
	gui_entry_set_i(gui->pt_depth, gui->ptr_settings->sample_depth);
	gtk_switch_set_active(gui->motion_blur, gui->ptr_settings->motion_blur);
	gui_control_hide(&gui->control);
}

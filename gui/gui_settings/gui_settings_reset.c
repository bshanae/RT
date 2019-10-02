/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_settings_reset.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:03:17 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 17:03:22 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_settings.h"

void				gui_settings_reset(t_gui_settings *gui)
{
	rt_assert_critical(gui->connected, "GUI Settings : Not connected");
	gui_entry_set_i(gui->pt_samples_limit, gui->ptr_settings->sample_limit);
	gui_entry_set_i(gui->pt_depth, gui->ptr_settings->sample_depth);
	gui_entry_set_i(gui->rm_steps, gui->ptr_settings->rm_step_limit);
	gui_entry_set_f(gui->rm_part, gui->ptr_settings->rm_step_part);
	gui_entry_set_f(gui->rm_distance, gui->ptr_settings->rm_max_distance);
	gui_entry_set_f(gui->illumination_value,
			gui->ptr_settings->illumination_value);
}

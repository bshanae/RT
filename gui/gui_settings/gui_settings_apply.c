/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_settings_apply.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:00:31 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 17:00:43 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_settings.h"

static RT_F			static_bound(RT_F value)
{
	if (value < (RT_F)0.01)
		return ((RT_F)0.01);
	if (value > (RT_F)1.)
		return (RT_F)1.;
	return (value);
}

void				gui_settings_apply(t_gui_settings *gui)
{
	rt_assert_critical(gui->connected, "GUI Settings : Not connected");
	gui->ptr_settings->sample_limit = gui_entry_get_i(gui->pt_samples_limit);
	gui->ptr_settings->sample_depth = gui_entry_get_i(gui->pt_depth);
	gui->ptr_settings->rm_step_limit = gui_entry_get_i(gui->rm_steps);
	gui->ptr_settings->rm_step_part =
		static_bound(gui_entry_get_f(gui->rm_part));
	gui->ptr_settings->rm_max_distance = gui_entry_get_f(gui->rm_distance);
	gui->ptr_settings->illumination_value =
		gui_entry_get_f(gui->illumination_value);
}

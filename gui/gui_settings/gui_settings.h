/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_settings.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:00:05 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 17:00:20 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_SETTINGS_H
# define GUI_SETTINGS_H

# include "rt_parameters.h"

# include "libft_standart.h"
# include "error_framework.h"
# include "gui_entry.h"
# include "gui_control.h"
# include "rt_settings.h"

# include <gtk/gtk.h>

typedef struct		s_gui_setting
{
	t_rt_bool		connected;
	t_rt_settings	*ptr_settings;
	t_gui_control	control;
	t_rt_bool		tracing_block;
	GtkToggleButton	*tracing_rt;
	GtkToggleButton	*tracing_rm;
	GtkStack		*stack;
	GtkEntry		*rm_steps;
	GtkEntry		*rm_part;
	GtkEntry		*rm_distance;
	GtkToggleButton	*light_basic;
	GtkToggleButton	*light_area;
	GtkSwitch		*illumination_state;
	GtkEntry		*illumination_value;
	GtkEntry		*pt_samples_number;
	GtkEntry		*pt_samples_limit;
	GtkEntry		*pt_depth;
	GtkSwitch		*motion_blur;
}					t_gui_settings;

t_gui_settings		*gui_settings_new(GtkBuilder *builder);
void				gui_settings_connect(t_gui_settings *settings, ...);
void				gui_settings_delete(t_gui_settings **settings);

void				gui_settings_show_samples(t_gui_settings *gui);
void				gui_settings_show(t_gui_settings *gui);
void				gui_settings_reset(t_gui_settings *gui);
void				gui_settings_apply(t_gui_settings *gui);

#endif

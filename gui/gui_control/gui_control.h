/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_control.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:18:57 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_CONTROL_H
# define GUI_CONTROL_H

# include "rt_parameters.h"

# include <gtk/gtk.h>

typedef struct		s_gui_init_control
{
	char			stack[64];
}					t_gui_init_control;

typedef struct		s_gui_control
{
	GtkStack		*stack;
	t_rt_bool		silent;
}					t_gui_control;

t_gui_control		gui_control_init
					(t_gui_init_control *init, GtkBuilder *builder);

void				gui_control_show
					(t_gui_control *control);
void				gui_control_hide
					(t_gui_control *control);

#endif

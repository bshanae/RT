/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_control_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:18:43 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_control.h"

t_gui_control		gui_control_init
	(t_gui_init_control *init, GtkBuilder *builder)
{
	t_gui_control	control;

	control.stack = RT_GUI_GET(builder, init->stack);
	control.silent = rt_false;
	gui_control_hide(&control);
	return (control);
}

void				gui_control_show(t_gui_control *control)
{
	if (control->silent == rt_true)
		return ;
	gtk_stack_set_visible_child_name(control->stack, "page_show");
}

void				gui_control_hide(t_gui_control *control)
{
	gtk_stack_set_visible_child_name(control->stack, "page_hide");
}

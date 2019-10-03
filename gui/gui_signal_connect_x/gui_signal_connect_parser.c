/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_connect_parser.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:23:18 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:23:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_connect_x.h"

void				gui_signal_connect_parser(t_gui *gui)
{
	printf("GUI Signal: Connecting parser callbacks\n");
	RT_GUI_CONNECT(gui, gui_signal_parser_select);
	RT_GUI_CONNECT(gui, gui_signal_parser_load);
}

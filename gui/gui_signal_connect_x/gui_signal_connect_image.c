/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_connect_image.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:22:54 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:22:54 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_connect_x.h"

void				gui_signal_connect_image(t_gui *gui)
{
	printf("GUI Signal: Connecting image callbacks\n");
	RT_GUI_CONNECT(gui, gui_signal_image_click);
	RT_GUI_CONNECT(gui, gui_signal_image_draw);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:46:15 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:46:15 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_x.h"

void				gui_signal_exit(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui_queue_finish(gui->queue);
	gtk_main_quit();
}

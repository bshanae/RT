/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_entry_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:45:04 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:45:07 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_x.h"

void				gui_signal_entry_launch_control_on_insert
	(GtkEntry *entry, const char *new, int length, int *position, gpointer ptr)
{
	t_gui			*gui;
	int				i;

	gui = (t_gui *)ptr;
	i = gui_notebook_camera;
	while (i < 4)
	{
		if (gtk_widget_is_ancestor(GTK_WIDGET(entry), gui->notebook_page[i]))
			break ;
		i++;
	}
	if (i != gui_notebook_end)
		gui_control_show(gui->notebook_control[i]);
}

void					gui_signal_entry_launch_control_on_delete
	(GtkEntry *entry, int start, int end, gpointer ptr)
{
	t_gui			*gui;
	int				i;

	gui = (t_gui *)ptr;
	i = gui_notebook_camera;
	while (i < 4)
	{
		if (gtk_widget_is_ancestor(GTK_WIDGET(entry), gui->notebook_page[i]))
			break ;
		i++;
	}
	if (i != gui_notebook_end)
		gui_control_show(gui->notebook_control[i]);
}

void				gui_signal_entry_block_i
	(GtkEntry *entry, const char *new, int length, int *position, gpointer ptr)
{
	int				block;
	int				i;

	block = 0;
	i = 0;
	while (i < length)
	{
		if (!is_dec(new + i) && new[i] != '-')
			block = 1;
		i++;
	}
	if (block)
		g_signal_stop_emission_by_name(G_OBJECT(entry), "insert_text");
}

void				gui_signal_entry_block_f
	(GtkEntry *entry, const char *new, int length, int *position, gpointer ptr)
{
	CHAR_REF		old;
	int				block;
	int				dot_count;
	int				i;

	block = 0;
	dot_count = 0;
	old = gtk_entry_get_text(entry);
	i = 0;
	while (old[i])
		dot_count += old[i++] == '.';
	i = 0;
	while (i < length)
	{
		dot_count += new[i] == '.';
		if (dot_count > 1)
			block = 1;
		if (!is_dec(new + i) && new[i] != '.' && new[i] != '-')
			block = 1;
		i++;
	}
	if (block)
		g_signal_stop_emission_by_name(G_OBJECT(entry), "insert_text");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_entry_set_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:34:09 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_entry.h"

void				gui_entry_set_str(GtkEntry *entry, const char *str)
{
	gtk_entry_set_text(entry, str);
}

void				gui_entry_set_f(GtkEntry *entry, RT_F value)
{
	static char		buffer[32];

	sprintf(buffer, "%.2f", (float)value);
	gtk_entry_set_text(entry, buffer);
}

void				gui_entry_set_i(GtkEntry *entry, int value)
{
	static char		buffer[32];

	sprintf(buffer, "%i", value);
	gtk_entry_set_text(entry, buffer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_entry_get_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:33:54 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:33:54 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_entry.h"

const char			*gui_entry_get_str(GtkEntry *entry)
{
	const char		*str;

	str = gtk_entry_get_text(entry);
	if (!str[0])
		str = gtk_entry_get_placeholder_text(entry);
	return (str);
}

RT_F				gui_entry_get_f(GtkEntry *entry)
{
	const char		*str;

	if (!(str = gui_entry_get_str(entry)))
	{
		rt_raise_warning("GUI Entry : Content is NULL");
		return ((RT_F)0.);
	}
	return ((RT_F)strtod(str, NULL));
}

int					gui_entry_get_i(GtkEntry *entry)
{
	const char		*str;

	str = gui_entry_get_str(entry);
	return ((int)strtol(str, NULL, 10));
}

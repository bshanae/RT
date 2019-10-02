/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_entry.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:33:48 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:33:48 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_ENTRY_H
# define GUI_ENTRY_H

# include "rt_float.h"

# include "error_framework.h"

# include <gtk/gtk.h>

const char			*gui_entry_get_str(GtkEntry *entry);
RT_F				gui_entry_get_f(GtkEntry *entry);
int					gui_entry_get_i(GtkEntry *entry);

void				gui_entry_set_str(GtkEntry *entry, const char *str);
void				gui_entry_set_f(GtkEntry *entry, RT_F value);
void				gui_entry_set_i(GtkEntry *entry, int value);

#endif

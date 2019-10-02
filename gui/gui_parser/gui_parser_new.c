/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_parser_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:44:01 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 15:44:01 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_parser.h"

t_gui_parser		*gui_parser_new(GtkBuilder *builder)
{
	t_gui_parser	*new;

	printf("GUI : Initializing parser\n");
	new = (t_gui_parser *)rt_malloc(sizeof(t_gui_parser));
	new->list = RT_GUI_GET(builder, "parser_list");
	new->selection = RT_GUI_GET(builder, "parser_selection");
	new->load = RT_GUI_GET(builder, "parser_load");
	gtk_widget_set_opacity(GTK_WIDGET(new->load), 0.);
	return (new);
}

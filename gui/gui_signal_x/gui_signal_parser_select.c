/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_parser_select.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:49:46 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_x.h"

void				gui_signal_parser_select
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	GtkTreeModel	*model;
	GtkTreeIter		iter;
	char			*name;

	gui = (t_gui *)ptr;
	if (!gtk_tree_selection_get_selected(gui->parser->selection, &model, &iter))
		return ;
	gtk_tree_model_get(model, &iter, 0, &name, -1);
	if (!name)
		return ;
	ft_strcpy(gui->parser->final_path, RT_SOURCE_GUI_SCENES);
	ft_strcat(gui->parser->final_path, "/");
	ft_strcat(gui->parser->final_path, name);
	gtk_widget_set_opacity(GTK_WIDGET(gui->parser->load), 1.);
}

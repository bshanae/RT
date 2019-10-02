/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_parser_update.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:44:13 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 15:44:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_parser.h"

void				gui_parser_update(t_gui_parser *parser)
{
	GtkTreeIter		iter;
	DIR				*directory;
	struct dirent	*file;

	gtk_list_store_clear(parser->list);
	directory = opendir(RT_SOURCE_GUI_SCENES);
	rt_assert(directory != NULL,
		"GUI Parser : Directory error (directory = %s)",
		RT_SOURCE_GUI_SCENES);
	if (!directory)
		return ;
	while ((file = readdir(directory)))
	{
		if (ft_strstr(file->d_name, ".json") == NULL)
			continue ;
		gtk_list_store_append(parser->list, &iter);
		gtk_list_store_set(parser->list, &iter, 0, file->d_name, -1);
	}
	closedir(directory);
}

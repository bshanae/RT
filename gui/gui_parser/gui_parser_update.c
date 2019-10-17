/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_parser_update.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:44:13 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_parser.h"

static int			static_cmp(const void *left, const void *right)
{
	return (ft_strcmp(left, right));
}

static void			static_print(char *str, t_gui_parser *parser)
{
	GtkTreeIter		iter;

	gtk_list_store_append(parser->list, &iter);
	gtk_list_store_set(parser->list, &iter, 0, str, -1);
}

void				gui_parser_update(t_gui_parser *parser)
{
	DIR				*directory;
	struct dirent	*file;
	t_btree			*root;

	gtk_list_store_clear(parser->list);
	directory = opendir(RT_SOURCE_GUI_SCENES);
	if (!directory)
		return (rt_raise_warning("GUI Parser : Directory error"));
	root = NULL;
	while ((file = readdir(directory)))
	{
		if (ft_strstr(file->d_name, ".json") == NULL)
			continue ;
		btree_insert(&root, file->d_name, 256, static_cmp);
	}
	btree_infix(root, (void (*)(void *, void *))static_print, parser);
	closedir(directory);
	btree_clean(&root, NULL);
}

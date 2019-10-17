/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:43:24 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_PARSER_H
# define GUI_PARSER_H

# include "rt_parameters.h"
# include "rt_sources_gui.h"

# include "error_framework.h"

# include "libft_btree.h"

# include <gtk/gtk.h>
# include <dirent.h>

typedef struct				s_gui_parser
{
	GtkListStore			*list;
	GtkTreeSelection		*selection;
	GtkButton				*load;
	char					final_path[128];
}							t_gui_parser;

t_gui_parser				*gui_parser_new(GtkBuilder *builder);
void						gui_parser_delete(t_gui_parser **parser);

void						gui_parser_update(t_gui_parser *parser);

#endif

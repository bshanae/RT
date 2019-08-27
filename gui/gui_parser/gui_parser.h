#ifndef GUI_PARSER_H
# define GUI_PARSER_H

# include "rt_parameters.h"

# include "assert.h"

# include <gtk/gtk.h>

typedef struct 				s_gui_parser
{
	GtkListStore			*list;
	GtkTreeView				*tree;
	GtkTreeSelection		*selection;
	GtkButton				*load;
	GtkFileChooserDialog	*dialog;
	GtkButton				*dialog_run;
	GtkEntry				*dialog_entry;
	const char 				*dialog_str_full;
	const char				*dialog_str_name;
	char 					final_path[128];
}							t_gui_parser;

t_gui_parser				*gui_parser_new(GtkBuilder *builder);
void						gui_parser_delete(t_gui_parser **parser);

void 						gui_parser_update(t_gui_parser *parser);

#endif

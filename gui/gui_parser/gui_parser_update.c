#include "gui_parser.h"

#include <dirent.h>

void 				gui_parser_update(t_gui_parser *parser)
{
	GtkTreeIter		iter;
	DIR				*directory;
	struct dirent	*file;

	gtk_list_store_clear(parser->list);
	FT_ASSERT((directory = opendir(RT_GUI_SCENES)) != NULL);
	while ((file = readdir(directory)))
	{
		if (ft_strstr(file->d_name, ".json") == NULL)
			continue ;
		gtk_list_store_append(parser->list, &iter);
		gtk_list_store_set(parser->list, &iter, 0, file->d_name, -1);
	}
	closedir(directory);
}
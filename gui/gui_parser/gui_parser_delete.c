#include "gui_parser.h"

void				gui_parser_delete(t_gui_parser **parser)
{
	free(*parser);
	*parser = NULL;
}
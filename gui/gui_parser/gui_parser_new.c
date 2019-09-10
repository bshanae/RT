#include "gui_parser.h"

t_gui_parser		*gui_parser_new(GtkBuilder *builder)
{
	t_gui_parser	*new;

	printf("GUI : Initializing parser\n");
	new = (t_gui_parser *)malloc(sizeof(t_gui_parser));
	new->list = RT_GUI_GET(builder, "parser_list");
	new->selection = RT_GUI_GET(builder, "parser_selection");
	new->load = RT_GUI_GET(builder, "parser_load");
	gtk_widget_set_opacity(GTK_WIDGET(new->load), 0.);
	new->dialog = RT_GUI_GET(builder, "parser_dialog");
	new->dialog_run = RT_GUI_GET(builder, "parser_dialog_run");
	new->dialog_entry = RT_GUI_GET(builder, "parser_dialog_entry");
	new->dialog_str_full = NULL;
	new->dialog_str_name = NULL;
	return (new);
}
#include "gui_signal_x.h"

void 				gui_signal_parser_dialog_run
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	int 			response;
	const char		*str;
	char			buffer[64];

	gui = (t_gui *)ptr;
	gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(gui->parser->dialog),
		".");
	response = gtk_dialog_run(GTK_DIALOG(gui->parser->dialog));
	gtk_widget_hide(GTK_WIDGET(gui->parser->dialog));
	if (response != GTK_RESPONSE_YES)
		return ;
	str = ft_strrchr(gui->parser->dialog_str_full, '/') + 1;
	if (!str)
		str = gui->parser->dialog_str_full;
	gtk_widget_set_opacity(GTK_WIDGET(gui->parser->load), 1.);
	ft_strcpy(buffer, ".../");
	ft_strcat(buffer, str);
	ft_strcpy(gui->parser->final_path, gui->parser->dialog_str_full);
	gtk_button_set_label(gui->parser->dialog_run, buffer);
	gtk_tree_selection_unselect_all(gui->parser->selection);
}

void 				gui_signal_parser_dialog_select
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	t_gui_parser	*parser;

	gui = (t_gui *)ptr;
	parser = gui->parser;
	parser->dialog_str_full =
		gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(parser->dialog));
	if (!parser->dialog_str_full)
		return ;
	gtk_entry_set_text(parser->dialog_entry, parser->dialog_str_full);
}

void 				gui_signal_parser_dialog_response_close
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gtk_dialog_response(GTK_DIALOG(gui->parser->dialog), GTK_RESPONSE_CLOSE);
}

void 				gui_signal_parser_dialog_response_yes
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	if (!ft_strstr(gui->parser->dialog_str_full, ".json"))
		return ;
	gtk_dialog_response(GTK_DIALOG(gui->parser->dialog), GTK_RESPONSE_YES);
}

void 				gui_signal_parser_dialog_response_no
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gtk_dialog_response(GTK_DIALOG(gui->parser->dialog), GTK_RESPONSE_NO);
}



#include "gui_signal_x.h"

void				gui_signal_settings_entry_changed
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gtk_widget_set_opacity(GTK_WIDGET(gui->settings->control), 1.);
}

void				gui_signal_settings_entry_insert
					(GtkEntry *entry, const char *new,
					int length, int *position, gpointer ptr)
{
	t_gui			*gui;
	int 			i;
	char			old[64];

	gui = (t_gui *)ptr;
	ft_strcpy(old, gtk_entry_get_text(entry));
	g_signal_stop_emission_by_name(G_OBJECT(entry), "insert_text");
	i = 0;
	while (i < length)
		if (!is_dec(new + i) && new[i] != '.' && new[i] != '-')
			return;
		else
			i++;
	g_signal_handlers_block_by_func(G_OBJECT(entry),
		G_CALLBACK(gui_signal_settings_entry_insert), ptr);
	gtk_editable_insert_text(GTK_EDITABLE(entry), new, length, position);
	g_signal_handlers_unblock_by_func(G_OBJECT(entry),
		G_CALLBACK(gui_signal_settings_entry_insert), ptr);
	if (old[0] && strtod(old, NULL) != strtod(gtk_entry_get_text(entry), NULL))
		gtk_widget_set_opacity(GTK_WIDGET(gui->settings->control), 1.);
}

void 				gui_signal_settings_entry_delete
					(GtkEntry *entry, int start, int end, gpointer ptr)
{
	t_gui			*gui;
	char			old[64];

	gui = (t_gui *)ptr;
	ft_strcpy(old, gtk_entry_get_text(entry));
	g_signal_stop_emission_by_name(G_OBJECT(entry), "delete_text");
	g_signal_handlers_block_by_func(G_OBJECT(entry),
		G_CALLBACK(gui_signal_settings_entry_delete), ptr);
	gtk_editable_delete_text(GTK_EDITABLE(entry), start, end);
	g_signal_handlers_unblock_by_func(G_OBJECT(entry),
		G_CALLBACK(gui_signal_settings_entry_delete), ptr);
	if (old[0] && strtod(old, NULL) != strtod(gtk_entry_get_text(entry), NULL))
		gtk_widget_set_opacity(GTK_WIDGET(gui->settings->control), 1.);
}
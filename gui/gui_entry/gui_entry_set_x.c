#include "gui_entry.h"

void				gui_entry_set_str(GtkEntry *entry, const char *str)
{
	gtk_entry_set_text(entry, str);
}

void				gui_entry_set_f(GtkEntry *entry, RT_F value)
{
	static char 	buffer[32];

	sprintf(buffer, "%.2f", value);
	gtk_entry_set_text(entry, buffer);
}

void				gui_entry_set_i(GtkEntry *entry, int value)
{
	static char 	buffer[32];

	sprintf(buffer, "%i", value);
	gtk_entry_set_text(entry, buffer);
}
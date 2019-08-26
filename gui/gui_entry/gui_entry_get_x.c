#include "gui_entry.h"

const char			*gui_entry_get_str(GtkEntry *entry)
{
	const char		*str;

	str = gtk_entry_get_text(entry);
	if (!str[0])
		str = gtk_entry_get_placeholder_text(entry);
	return (str);
}

RT_F				gui_entry_get_f(GtkEntry *entry)
{
	const char		*str;

	str = gui_entry_get_str(entry);
	return ((RT_F)strtod(str, NULL));
}

int					gui_entry_get_i(GtkEntry *entry)
{
	const char		*str;

	str = gui_entry_get_str(entry);
	return ((int)strtol(str, NULL, 10));
}
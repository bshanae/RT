#ifndef GUI_ENTRY_H
# define GUI_ENTRY_H

# include "rt_float.h"

# include <gtk/gtk.h>

const char			*gui_entry_get_str(GtkEntry *entry);
RT_F				gui_entry_get_f(GtkEntry *entry);
int					gui_entry_get_i(GtkEntry *entry);

void				gui_entry_set_str(GtkEntry *entry, const char *str);
void				gui_entry_set_f(GtkEntry *entry, RT_F value);
void				gui_entry_set_i(GtkEntry *entry, int value);

#endif

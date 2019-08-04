#ifndef GUI_SIGNALS_H
# define GUI_SIGNALS_H

# include "gui.h"
# include "gui_object.h"

void				gui_signal_connect(t_gui *gui);

void				gui_signal_selected(
					GtkTreeSelection *select,
					gpointer ptr);
void				gui_signal_sphere_pos_x(GtkEntry *entry, gpointer ptr);


#endif

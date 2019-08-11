#ifndef GUI_SIGNAL_H
# define GUI_SIGNAL_H

# include "gui.h"

# define GTK_SIGNAL_SIGNATURE GtkWidget *w, gpointer p

void 				gui_signal_exit(GTK_SIGNAL_SIGNATURE);

gboolean			gui_signal_key
					(GtkWidget *window, GdkEventKey *key, gpointer ptr);

void 				gui_signal_scene_edit_select
					(GtkWidget *widget, gpointer ptr);

void 				gui_signal_object_edit_sphere_px(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_object_edit_sphere_py(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_object_edit_sphere_pz(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_object_edit_sphere_r(GTK_SIGNAL_SIGNATURE);



#endif

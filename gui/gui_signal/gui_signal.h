#ifndef GUI_SIGNAL_H
# define GUI_SIGNAL_H

# include "gui.h"

# define GTK_SIGNAL_SIGNATURE GtkWidget *, gpointer


void 				gui_signal_edit_sphere_px(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_edit_sphere_py(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_edit_sphere_pz(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_edit_sphere_r(GTK_SIGNAL_SIGNATURE);



#endif

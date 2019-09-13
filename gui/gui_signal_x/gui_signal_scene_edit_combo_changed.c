#include "gui_signal_x.h"

void				gui_signal_scene_edit_combo_changed
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;

	gui = (t_gui *)ptr;
	gui_control_show(&gui->scene->edit->control);
}
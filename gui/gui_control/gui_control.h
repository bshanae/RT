#ifndef GUI_CONTROL_H
# define GUI_CONTROL_H

# include "rt_parameters.h"

# include <gtk/gtk.h>

typedef struct 		s_gui_init_control
{
	char			stack[64];
}					t_gui_init_control;

typedef struct 		s_gui_control
{
	GtkStack		*stack;
}					t_gui_control;

t_gui_control		gui_control_init
					(t_gui_init_control *init, GtkBuilder *builder);

void				gui_control_show
					(t_gui_control *control);
void				gui_control_hide
					(t_gui_control *control);

#endif

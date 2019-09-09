#include "gui_control.h"

t_gui_control		gui_control_init
	(t_gui_init_control *init, GtkBuilder *builder)
{
	t_gui_control	control;

	control.stack = RT_GUI_GET(builder, init->stack);
	gui_control_hide(&control);
	return (control);
}

void				gui_control_show(t_gui_control *control)
{
	gtk_stack_set_visible_child_name(control->stack, "page_show");
}

void				gui_control_hide(t_gui_control *control)
{
	gtk_stack_set_visible_child_name(control->stack, "page_hide");
}
#include "gui_object_x.h"


t_gui_object_mandelbulb		gui_object_mandelbulb_init
							(t_gui_init_mandelbulb *init, GtkBuilder *builder)
{
	t_gui_object_mandelbulb	mandelbulb;

	mandelbulb.iterations = RT_GUI_GET(builder, init->iterations);
	mandelbulb.power = RT_GUI_GET(builder, init->power);
	return (mandelbulb);
}

void						gui_object_mandelbulb_get
							(t_gui_object_mandelbulb *gui, t_object *object)
{
	t_object_mandelbulb		*data;

	data = (t_object_mandelbulb *)object->data;
	gui_entry_set_i(gui->iterations, data->iterations);
	gui_entry_set_f(gui->power, data->power);
}

void 						gui_object_mandelbulb_set
							(t_gui_object_mandelbulb *gui, t_object *object)
{
	t_object_mandelbulb		*data;

	data = (t_object_mandelbulb *)object->data;
	data->iterations = gui_entry_get_i(gui->iterations);
	data->power = gui_entry_get_f(gui->power);
}

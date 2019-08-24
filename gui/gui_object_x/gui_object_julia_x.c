#include "gui_object_x.h"

t_gui_object_julia			gui_object_julia_init
							(t_gui_init_julia *init, GtkBuilder *builder)
{
	t_gui_object_julia		julia;

	julia.iterations = RT_GUI_GET(builder, init->iterations);
	julia.value_x = RT_GUI_GET(builder, init->value_x);
	julia.value_y = RT_GUI_GET(builder, init->value_y);
	julia.value_z = RT_GUI_GET(builder, init->value_z);
	julia.value_w = RT_GUI_GET(builder, init->value_w);
	return (julia);
}

void						gui_object_julia_get
							(t_gui_object_julia *gui, t_object *object)
{
	t_object_julia			*data;

	data = (t_object_julia *)object->data;
	gui_entry_set_i(gui->iterations, data->iterations);
	gui_entry_set_f(gui->value_x, data->value.x);
	gui_entry_set_f(gui->value_y, data->value.y);
	gui_entry_set_f(gui->value_z, data->value.z);
	gui_entry_set_f(gui->value_w, data->value.w);
}

void 						gui_object_julia_set
							(t_gui_object_julia *gui, t_object *object)
{
	t_object_julia			*data;

	data = (t_object_julia *)object->data;
	gui_entry_set_i(gui->iterations, data->iterations);
	gui_entry_set_f(gui->value_x, data->value.x);
	gui_entry_set_f(gui->value_y, data->value.y);
	gui_entry_set_f(gui->value_z, data->value.z);
	gui_entry_set_f(gui->value_w, data->value.w);
}

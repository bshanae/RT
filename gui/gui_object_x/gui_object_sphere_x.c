#include "gui_object_x.h"

t_gui_object_sphere		gui_object_sphere_init
						(t_gui_init_sphere *init, GtkBuilder *builder)
{
	t_gui_object_sphere	sphere;

	sphere.position_x = RT_GUI_GET(builder, init->position_x);
	sphere.position_y = RT_GUI_GET(builder, init->position_y);
	sphere.position_z = RT_GUI_GET(builder, init->position_z);
	sphere.radius = RT_GUI_GET(builder, init->radius);
	return (sphere);
}

void					gui_object_sphere_get
						(t_gui_object_sphere *gui, t_object *object)
{
	t_object_sphere		*data;

	data = (t_object_sphere *)object->data;
	gui_entry_set_f(gui->position_x, data->position.x);
	gui_entry_set_f(gui->position_y, data->position.y);
	gui_entry_set_f(gui->position_z, data->position.z);
	gui_entry_set_f(gui->radius, data->radius);
}

void 					gui_object_sphere_set
						(t_gui_object_sphere *gui, t_object *object)
{
	t_object_sphere	*data;

	data = (t_object_sphere *)object->data;
	data->position.x = gui_entry_get_f(gui->position_x);
	data->position.y = gui_entry_get_f(gui->position_y);
	data->position.z = gui_entry_get_f(gui->position_z);
	data->radius = gui_entry_get_f(gui->radius);
}
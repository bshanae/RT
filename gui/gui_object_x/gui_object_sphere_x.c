#include "gui_object_x.h"

t_gui_object_sphere		gui_object_sphere_set
						(t_gui_init_sphere *init, GtkBuilder *builder)
{
	t_gui_object_sphere	sphere;

	sphere.box = GTK_BOX(RT_GUI_GET(builder, init->box));
	sphere.offscreen = GTK_VIEWPORT(RT_GUI_GET(builder, init->offscreen));
	if (init->name[0])
		sphere.name = GTK_ENTRY(RT_GUI_GET(builder, init->name));
	else
		sphere.name = NULL;
	sphere.position_x = GTK_ENTRY(RT_GUI_GET(builder, init->position_x));
	sphere.position_y = GTK_ENTRY(RT_GUI_GET(builder, init->position_y));
	sphere.position_z = GTK_ENTRY(RT_GUI_GET(builder, init->position_z));
	sphere.radius = GTK_ENTRY(RT_GUI_GET(builder, init->radius));
	return (sphere);
}

void					gui_object_sphere_show
						(t_gui_object_sphere *gui, t_object *object)
{
	t_object_sphere		*data;

	data = object ? (t_object_sphere *)object->data : NULL;
	if (gui->name && object)
		gtk_entry_set_text(gui->name, object->name);
	if (!data)
		return ;
	gui_object_x_set_f(gui->position_x, data->position.x);
	gui_object_x_set_f(gui->position_y, data->position.y);
	gui_object_x_set_f(gui->position_z, data->position.z);
	gui_object_x_set_f(gui->radius, data->radius);
}

void 					gui_object_sphere_build
						(t_gui_object_sphere *gui, t_object *object)
{
	t_object_sphere	*data;

	data = (t_object_sphere *)object->data;
	ft_strcpy(object->name, gui_object_x_get_str(gui->name));
	object->type = object_sphere;
	data->position.x = gui_object_x_get_f(gui->position_x);
	data->position.y = gui_object_x_get_f(gui->position_y);
	data->position.z = gui_object_x_get_f(gui->position_z);
	data->radius = gui_object_x_get_f(gui->radius);
}
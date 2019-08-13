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
						(t_gui_object_sphere *edit, t_object *object)
{
	t_object_sphere		*data;
	char 				buffer[32];

	data = object ? (t_object_sphere *)object->data : NULL;
	ft_bzero(buffer, 32);
	if (edit->name && object)
		gtk_entry_set_text(edit->name, object->name);
	if (data)
		sprintf(buffer, "%.2f", data->position.x);
	gtk_entry_set_text(edit->position_x, buffer);
	if (data)
		sprintf(buffer, "%.2f", data->position.y);
	gtk_entry_set_text(edit->position_y, buffer);
	if (data)
		sprintf(buffer, "%.2f", data->position.z);
	gtk_entry_set_text(edit->position_z, buffer);
	if (data)
		sprintf(buffer, "%.2f", data->radius);
	gtk_entry_set_text(edit->radius, buffer);
}

void 					gui_object_sphere_build
						(t_gui_object_sphere *gui, t_object *object)
{
	t_object_sphere	*data;

	data = (t_object_sphere *)object->data;
	ft_strcpy(object->name, gui_object_x_get_parameter(gui->name));
	object->type = object_sphere;
	data->position.x =
		(RT_F)strtod(gui_object_x_get_parameter(gui->position_x), NULL);
	data->position.y =
		(RT_F)strtod(gui_object_x_get_parameter(gui->position_y), NULL);
	data->position.z =
		(RT_F)strtod(gui_object_x_get_parameter(gui->position_z), NULL);
	data->radius = (RT_F)strtod(gui_object_x_get_parameter(gui->radius), NULL);
}
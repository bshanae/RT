#include "gui_object_x.h"

t_gui_object_plane		gui_object_plane_set
						(t_gui_init_plane *init, GtkBuilder *builder)
{
	t_gui_object_plane	plane;

	plane.box = GTK_BOX(RT_GUI_GET(builder, init->box));
	plane.offscreen = GTK_VIEWPORT(RT_GUI_GET(builder, init->offscreen));
	if (init->name[0])
		plane.name = GTK_ENTRY(RT_GUI_GET(builder, init->name));
	else
		plane.name = NULL;
	plane.position_x = GTK_ENTRY(RT_GUI_GET(builder, init->position_x));
	plane.position_y = GTK_ENTRY(RT_GUI_GET(builder, init->position_y));
	plane.position_z = GTK_ENTRY(RT_GUI_GET(builder, init->position_z));
	plane.normal_x = GTK_ENTRY(RT_GUI_GET(builder, init->normal_x));
	plane.normal_y = GTK_ENTRY(RT_GUI_GET(builder, init->normal_y));
	plane.normal_z = GTK_ENTRY(RT_GUI_GET(builder, init->normal_z));
	return (plane);
}

void 					gui_object_plane_show
						(t_gui_object_plane *edit, t_object *object)
{
	t_object_plane		*data;
	char 				buffer[32];

	data = object ? (t_object_plane *)object->data : NULL;
	if (edit->name && object)
		gtk_entry_set_text(edit->name, object->name);
	ft_bzero(buffer, 32);
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
		sprintf(buffer, "%.2f", data->normal.x);
	gtk_entry_set_text(edit->normal_x, buffer);
	if (data)
		sprintf(buffer, "%.2f", data->normal.y);
	gtk_entry_set_text(edit->normal_y, buffer);
	if (data)
		sprintf(buffer, "%.2f", data->normal.z);
	gtk_entry_set_text(edit->normal_z, buffer);
}

void 					gui_object_plane_build
						(t_gui_object_plane *gui, t_object *object)
{
	t_object_plane		*data;

	data = (t_object_plane *)object->data;
	ft_strcpy(object->name, gui_object_x_get_parameter(gui->name));
	object->type = object_plane;
	data->position.x =
		(RT_F)strtod(gui_object_x_get_parameter(gui->position_x), NULL);
	data->position.y =
		(RT_F)strtod(gui_object_x_get_parameter(gui->position_y), NULL);
	data->position.z =
		(RT_F)strtod(gui_object_x_get_parameter(gui->position_z), NULL);
	data->normal.x =
		(RT_F)strtod(gui_object_x_get_parameter(gui->normal_x), NULL);
	data->normal.y =
		(RT_F)strtod(gui_object_x_get_parameter(gui->normal_y), NULL);
	data->normal.z =
		(RT_F)strtod(gui_object_x_get_parameter(gui->normal_z), NULL);
}
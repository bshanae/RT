#include "gui_object_edit.h"

void 				gui_object_edit_plane_load
					(t_gui_object_edit_plane *edit, t_object *object)
{
	t_object_plane	*data;
	char 			buffer[32];

	data = (t_object_plane *)object->data;
	gtk_entry_set_text(edit->name, object->name);
	sprintf(buffer, "%.2f", data->position.x);
	gtk_entry_set_text(edit->position_x, buffer);
	sprintf(buffer, "%.2f", data->position.y);
	gtk_entry_set_text(edit->position_y, buffer);
	sprintf(buffer, "%.2f", data->position.z);
	gtk_entry_set_text(edit->position_z, buffer);
	sprintf(buffer, "%.2f", data->normal.x);
	gtk_entry_set_text(edit->normal_x, buffer);
	sprintf(buffer, "%.2f", data->normal.y);
	gtk_entry_set_text(edit->normal_y, buffer);
	sprintf(buffer, "%.2f", data->normal.z);
	gtk_entry_set_text(edit->normal_z, buffer);
}
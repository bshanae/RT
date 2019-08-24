#include "gui_scene_edit.h"

void 				gui_scene_edit_material_color_enable
					(t_gui_scene_edit *edit)
{
	gtk_widget_set_opacity(edit->material_color_box, 1.);
	gtk_editable_set_editable(GTK_EDITABLE(edit->material.color_r), 1);
	gtk_editable_set_editable(GTK_EDITABLE(edit->material.color_g), 1);
	gtk_editable_set_editable(GTK_EDITABLE(edit->material.color_b), 1);
	edit->material_color_silent = 0;
}

void 				gui_scene_edit_material_color_disable
					(t_gui_scene_edit *edit)
{
	gtk_widget_set_opacity(edit->material_color_box, 0.5);
	gtk_editable_set_editable(GTK_EDITABLE(edit->material.color_r), 0);
	gtk_editable_set_editable(GTK_EDITABLE(edit->material.color_g), 0);
	gtk_editable_set_editable(GTK_EDITABLE(edit->material.color_b), 0);
	edit->material_color_silent = 1;
}
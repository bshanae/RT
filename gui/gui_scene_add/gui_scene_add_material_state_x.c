#include "gui_scene_add.h"

void 				gui_scene_add_material_state_light
					(t_gui_scene_add *add)
{
	t_material		material;

	material.color = COLOR_BLACK;
	material.emission = COLOR_WHITE;
	gui_material_get(&add->material, &material);
	gtk_widget_set_opacity(add->material_color_box, 0.5);
	gtk_editable_set_editable(GTK_EDITABLE(add->material.color_r), 0);
	gtk_editable_set_editable(GTK_EDITABLE(add->material.color_g), 0);
	gtk_editable_set_editable(GTK_EDITABLE(add->material.color_b), 0);
	add->material_color_silent = 1;
}

void 				gui_scene_add_material_state_non_light
					(t_gui_scene_add *add)
{
	t_material		material;

	material.color = COLOR_WHITE;
	material.emission = COLOR_BLACK;
	gui_material_get(&add->material, &material);
	gtk_widget_set_opacity(add->material_color_box, 1.);
	gtk_editable_set_editable(GTK_EDITABLE(add->material.color_r), 1);
	gtk_editable_set_editable(GTK_EDITABLE(add->material.color_g), 1);
	gtk_editable_set_editable(GTK_EDITABLE(add->material.color_b), 1);
	add->material_color_silent = 0;
}
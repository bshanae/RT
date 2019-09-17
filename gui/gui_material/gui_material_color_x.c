#include "gui_material.h"

void 				gui_material_color_enable(t_gui_material *material)
{
	gtk_widget_set_opacity(material->color_box, 1.);
	gtk_editable_set_editable(GTK_EDITABLE(material->color_r), 1);
	gtk_editable_set_editable(GTK_EDITABLE(material->color_g), 1);
	gtk_editable_set_editable(GTK_EDITABLE(material->color_b), 1);
	material->color_silent = 0;
}

void 				gui_material_color_disable(t_gui_material *material)
{
	gtk_widget_set_opacity(material->color_box, 0.5);
	gtk_editable_set_editable(GTK_EDITABLE(material->color_r), 0);
	gtk_editable_set_editable(GTK_EDITABLE(material->color_g), 0);
	gtk_editable_set_editable(GTK_EDITABLE(material->color_b), 0);
	material->color_silent = 1;
}
#include "gui_material.h"

void 				gui_material_color_enable(t_gui_material *material)
{
	gtk_widget_set_sensitive(material->color_box, 1);
}

void 				gui_material_color_disable(t_gui_material *material)
{
	gtk_widget_set_sensitive(material->color_box, 0);
}
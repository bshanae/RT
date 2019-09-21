#include "gui_material.h"

void 				gui_material_special_disable(t_gui_material *material)
{
	gtk_widget_set_sensitive(GTK_WIDGET(material->reflectance_scale), FALSE);
	gtk_widget_set_sensitive(GTK_WIDGET(material->transparency_scale), FALSE);
}


void 				gui_material_special_enable(t_gui_material *material)
{
	gtk_widget_set_sensitive(GTK_WIDGET(material->reflectance_scale), TRUE);
	gtk_widget_set_sensitive(GTK_WIDGET(material->transparency_scale), TRUE);
}
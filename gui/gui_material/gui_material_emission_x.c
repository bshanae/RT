#include "gui_material.h"

void					gui_material_emission_enable(t_gui_material *material)
{
	gtk_widget_set_sensitive(material->emission_box, 1);
}

void					gui_material_emission_disable(t_gui_material *material)
{
	gtk_widget_set_sensitive(material->emission_box, 0);
}


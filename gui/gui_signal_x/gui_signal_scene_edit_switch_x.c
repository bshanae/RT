#include "gui_signal_x.h"

void				gui_signal_scene_edit_switch_material
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	t_gui_material	*material;
	gboolean 		state;

	gui = (t_gui *)ptr;
	material = &gui->scene->edit->material;
	if (gui->scene->edit->material.texture_state == rt_off)
	{
		rt_raise_warning("GUI Editor : Unexpected material stack state");
		return ;
	}
	state = gtk_toggle_button_get_active(material->switcher_material);
	g_signal_handlers_block_by_func(G_OBJECT(material->switcher_texture),
		gui_signal_scene_edit_switch_texture, ptr);
	gtk_toggle_button_set_active(material->switcher_texture, !state);
	g_signal_handlers_unblock_by_func(G_OBJECT(material->switcher_texture),
		gui_signal_scene_edit_switch_texture, ptr);
	gui_material_switch_mod(&gui->scene->edit->material, state ?
		gui_material_material : gui_material_texture);
}

void 				gui_signal_scene_edit_switch_texture
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	t_gui_material	*material;
	gboolean 		state;

	gui = (t_gui *)ptr;
	material = &gui->scene->edit->material;
	if (gui->scene->edit->material.texture_state == rt_off)
	{
		rt_raise_warning("GUI Editor : Unexpected material stack state");
		return ;
	}
	state = gtk_toggle_button_get_active(material->switcher_texture);
	g_signal_handlers_block_by_func(G_OBJECT(material->switcher_material),
		gui_signal_scene_edit_switch_material, ptr);
	gtk_toggle_button_set_active(material->switcher_material, !state);
	g_signal_handlers_unblock_by_func(G_OBJECT(material->switcher_material),
		gui_signal_scene_edit_switch_material, ptr);
	gui_material_switch_mod(&gui->scene->edit->material, state ?
		gui_material_texture : gui_material_material);
}
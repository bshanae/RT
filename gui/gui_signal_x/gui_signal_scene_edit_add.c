#include "gui_signal_x.h"

void				gui_signal_scene_edit_add
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	int				response;
	char			*str;

	gui = (t_gui *)ptr;
	gui->scene->edit->control.silent = 1;
	str =  gui_scene_add_gen_name(gui->scene->add);
	gtk_entry_set_placeholder_text(gui->scene->add->name, str);
	free(str);
	gtk_widget_grab_focus(GTK_WIDGET(gui->scene->add->type_combo));
	gui_scene_add_material_state_non_light(gui->scene->add);
	gtk_combo_box_set_active(gui->scene->add->type_combo, object_type_sphere);
	g_signal_emit_by_name(GTK_COMBO_BOX(gui->scene->add->type_combo), "changed");
	response = gtk_dialog_run(gui->scene->add->dialog);
	if (response == GTK_RESPONSE_YES)
	{
		scene_update(gui->renderer->data.scene);
		gui_scene_common_update_all(gui->scene->common,
			gui->renderer->data.scene, gui->renderer->data.settings.rm_mod);
		cl_renderer_flag_set(gui->renderer, cl_flag_update_scene);
		cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
		gui_queue_push(gui->queue);
	}
	gtk_widget_hide(GTK_WIDGET(gui->scene->add->dialog));
	gui->scene->edit->control.silent = 0;
}
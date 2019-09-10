#include "gui_signal_x.h"

void				gui_signal_scene_edit_add
					(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	int				response;

	gui = (t_gui *)ptr;
	gtk_entry_set_placeholder_text(gui->scene->add->name,
		gui_scene_add_gen_name(gui->scene->add));
	gtk_widget_grab_focus(GTK_WIDGET(gui->scene->add->type_combo));
	gui_scene_add_material_state_non_light(gui->scene->add);
	response = gtk_dialog_run(gui->scene->add->dialog);
	if (response == GTK_RESPONSE_YES)
	{
		gui_scene_common_update_all(gui->scene->common,
			gui->renderer->data.scene, gui->renderer->data.settings.rm_mod);
		cl_renderer_flag_set(gui->renderer, cl_flag_update_scene);
		cl_renderer_flag_set(gui->renderer, cl_flag_reset_samples);
		gui_queue_push(gui->queue);
	}
	gtk_widget_hide(GTK_WIDGET(gui->scene->add->dialog));
}
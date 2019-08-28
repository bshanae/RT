#include "gui_settings.h"

void 				gui_settings_show
					(t_gui_settings *gui, t_cl_renderer_settings *settings)
{
	gtk_widget_set_opacity(GTK_WIDGET(gui->control), 0.);
	gtk_toggle_button_set_active(gui->tracing_rt, !settings->rm_mod);
	gtk_toggle_button_set_active(gui->tracing_rm, settings->rm_mod);
	gui_entry_set_i(gui->rm_steps, settings->rm_step_limit);
	gui_entry_set_f(gui->rm_part, settings->rm_step_part);
	gui_entry_set_i(gui->rm_distance, settings->rm_max_distance);
	ASSERT((settings->light_basic && settings->light_area) != 1);
	gtk_toggle_button_set_active(gui->light_basic, settings->light_basic);
	gtk_toggle_button_set_active(gui->light_area, settings->light_area);
	gui_entry_set_i(gui->pt_samples, settings->sample_limit);
	gui_entry_set_i(gui->pt_depth, settings->sample_depth);
}
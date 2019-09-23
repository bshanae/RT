#include "gui_settings.h"

void 					gui_settings_show
						(t_gui_settings *gui, t_rt_settings *settings)
{
	t_rt_tracing_mod	mod;

	mod = settings->tracing_mod;
	gui->tracing_block = rt_true;
	gtk_toggle_button_set_active(gui->tracing_rt, mod == rt_tracing_rt);
	gtk_toggle_button_set_active(gui->tracing_rm, mod == rt_tracing_rm);
	gui->tracing_block = rt_false;
	gtk_stack_set_visible_child_name(gui->stack,
									 mod == rt_tracing_rt ? "rt" : "rm");
	gui_entry_set_i(gui->rm_steps, settings->rm_step_limit);
	gui_entry_set_f(gui->rm_part, settings->rm_step_part);
	gui_entry_set_f(gui->rm_distance, settings->rm_max_distance);
	gtk_toggle_button_set_active(gui->light_basic,
								 settings->light_mod == rt_light_basic);
	gtk_toggle_button_set_active(gui->light_area,
								 settings->light_mod == rt_light_area);
	gtk_switch_set_active(gui->illumination_state, settings->illumination);
	gui_entry_set_f(gui->illumination_value, settings->illumination_value);
	gui_entry_set_i(gui->pt_samples_number, settings->sample_count);
	gui_entry_set_i(gui->pt_samples_limit, settings->sample_limit);
	gui_entry_set_i(gui->pt_depth, settings->sample_depth);
	gtk_switch_set_active(gui->motion_blur, settings->motion_blur);
	gui_control_hide(&gui->control);
}
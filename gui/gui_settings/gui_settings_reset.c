#include "gui_settings.h"

void 				gui_settings_reset
					(t_gui_settings *gui, t_rt_settings *settings)
{
	gui_entry_set_i(gui->pt_samples_limit, settings->sample_limit);
	gui_entry_set_i(gui->pt_depth, settings->sample_depth);
	gui_entry_set_i(gui->rm_steps, settings->rm_step_limit);
	gui_entry_set_f(gui->rm_part, settings->rm_step_part);
	gui_entry_set_f(gui->rm_distance, settings->rm_max_distance);
	gui_entry_set_f(gui->illumination_value, settings->illumination_value);
}
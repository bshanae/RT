#include "gui_settings.h"

t_gui_settings		*gui_settings_new(GtkBuilder *builder)
{
	t_gui_settings	*new;

	new = malloc(sizeof(t_gui_settings));
	new->control = RT_GUI_GET(builder, "settings_control");
	new->tracing_rt = RT_GUI_GET(builder, "settings_tracing_rt");
	new->tracing_rm = RT_GUI_GET(builder, "settings_tracing_rm");
	new->stack = RT_GUI_GET(builder, "settings_stack");
	new->rm_steps = RT_GUI_GET(builder, "settings_rm_steps");
	new->rm_part = RT_GUI_GET(builder, "settings_rm_part");
	new->rm_distance = RT_GUI_GET(builder, "settings_rm_distance");
	new->light_basic = RT_GUI_GET(builder, "settings_light_basic");
	new->light_area = RT_GUI_GET(builder, "settings_light_area");
	new->pt_samples = RT_GUI_GET(builder, "settings_pt_samples");
	new->pt_depth = RT_GUI_GET(builder, "settings_pt_depth");
	return (new);
}
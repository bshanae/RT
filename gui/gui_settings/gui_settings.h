#ifndef GUI_SETTINGS_H
# define GUI_SETTINGS_H

# include "rt_parameters.h"
# include "cl_renderer_settings.h"

# include "libft_standart.h"
# include "error_framework.h"
# include "gui_entry.h"
# include "gui_control.h"

# include <gtk/gtk.h>

typedef struct 		s_gui_setting
{
	t_gui_control	control;
	GtkToggleButton	*tracing_rt;
	GtkToggleButton	*tracing_rm;
	GtkStack		*stack;
	GtkEntry		*rm_steps;
	GtkEntry		*rm_part;
	GtkEntry		*rm_distance;
	GtkToggleButton	*light_basic;
	GtkToggleButton	*light_area;
	GtkSwitch		*illumination_state;
	GtkEntry		*illumination_value;
	GtkEntry		*pt_samples;
	GtkEntry		*pt_depth;
}					t_gui_settings;

t_gui_settings		*gui_settings_new(GtkBuilder *builder);
void 				gui_settings_delete(t_gui_settings **settings);

void 				gui_settings_show
					(t_gui_settings *gui, t_cl_renderer_settings *settings);
void 				gui_settings_reset
					(t_gui_settings *gui, t_cl_renderer_settings *settings);
void 				gui_settings_apply
					(t_gui_settings *gui, t_cl_renderer_settings *settings);

#endif

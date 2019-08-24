#ifndef GUI_SETTINGS_H
# define GUI_SETTINGS_H

# include <gtk/gtk.h>

typedef struct 		s_gui_setting
{

}					t_gui_settings;

t_gui_settings		*gui_settings_new(GtkBuilder *builder);
void 				gui_settings_delete(t_gui_settings **settings);

#endif

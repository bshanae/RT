#ifndef GUI_SIGNAL_H
# define GUI_SIGNAL_H

# include "gui_entry.h"
# include "gui_control.h"
# include "gui.h"

# include <time.h>

# define GTK_SIGNAL_SIGNATURE GtkWidget *w, gpointer p

void 				gui_signal_exit
					(GTK_SIGNAL_SIGNATURE);
gboolean			gui_signal_key
					(GtkWidget *widget, GdkEventKey *event, gpointer ptr);

void				gui_signal_entry_launch_control_on_insert
					(GtkEntry *entry, const char *new,
					int length, int *position, gpointer ptr);
void 				gui_signal_entry_launch_control_on_delete
					(GtkEntry *entry, int start, int end, gpointer ptr);
void				gui_signal_entry_block_i
					(GtkEntry *entry, const char *new,
	 				int length, int *position, gpointer ptr);
void				gui_signal_entry_block_f
					(GtkEntry *entry, const char *new,
	 				int length, int *position, gpointer ptr);

void 				gui_signal_parser_select
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_parser_load
					(GTK_SIGNAL_SIGNATURE);

gboolean			gui_signal_camera_antialiasing
					(GtkWidget *widget, gboolean state, gpointer ptr);
void				gui_signal_camera_filter
					(GtkWidget *widget, gpointer ptr);
gboolean			gui_signal_camera_focus_enable
					(GtkWidget *widget, gboolean state, gpointer ptr);
void				gui_signal_camera_focus_auto
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_camera_screen_save
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_camera_screen_success_close
					(GTK_SIGNAL_SIGNATURE);
void				gui_signal_camera_screen_fail_close
					(GTK_SIGNAL_SIGNATURE);
void				gui_signal_camera_reset
					(GTK_SIGNAL_SIGNATURE);
void				gui_signal_camera_apply
					(GTK_SIGNAL_SIGNATURE);

void				gui_signal_scene_edit_combo_changed
					(GtkWidget *widget, gpointer ptr);
void 				gui_signal_scene_edit_select
					(GTK_SIGNAL_SIGNATURE);
void				gui_signal_scene_edit_reset
					(GTK_SIGNAL_SIGNATURE);
void				gui_signal_scene_edit_apply
					(GTK_SIGNAL_SIGNATURE);
void				gui_signal_scene_edit_switch_material
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_scene_edit_switch_texture
					(GTK_SIGNAL_SIGNATURE);
void				gui_signal_scene_edit_material_color
					(GTK_SIGNAL_SIGNATURE);
void				gui_signal_scene_edit_material_emission
					(GTK_SIGNAL_SIGNATURE);
void				gui_signal_scene_edit_add
					(GTK_SIGNAL_SIGNATURE);
void				gui_signal_scene_edit_remove
					(GTK_SIGNAL_SIGNATURE);
void				gui_signal_scene_edit_remove_response_cancel
					(GTK_SIGNAL_SIGNATURE);
void				gui_signal_scene_edit_remove_response_yes
					(GTK_SIGNAL_SIGNATURE);
void				gui_signal_scene_edit_remove_response_no
					(GTK_SIGNAL_SIGNATURE);

void				gui_signal_scene_add_response_cancel
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_scene_add_response_yes
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_scene_add_response_no
					(GTK_SIGNAL_SIGNATURE);
gboolean			gui_signal_scene_add_block_destroy
					(GtkWidget *widget, GdkEvent  *event, gpointer ptr);
void 				gui_signal_scene_add_type_select
					(GTK_SIGNAL_SIGNATURE);
void				gui_signal_scene_add_material_color
					(GTK_SIGNAL_SIGNATURE);
void				gui_signal_scene_add_material_emission
					(GTK_SIGNAL_SIGNATURE);

void 				gui_signal_settings_reset
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_settings_apply
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_settings_resize
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_settings_light
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_settings_tracing_rt
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_settings_tracing_rm
					(GTK_SIGNAL_SIGNATURE);

gboolean 			gui_signal_image_click
					(GtkWidget *widget, GdkEventButton *event, gpointer ptr);
gboolean			gui_signal_image_draw
					(GtkWidget *widget, void *cairo, gpointer ptr);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_x.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:01:45 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_SIGNAL_X_H
# define GUI_SIGNAL_X_H

# include "gui_entry.h"
# include "gui_control.h"
# include "gui.h"

# include <time.h>

void				gui_signal_exit
					(GtkWidget *widget, gpointer ptr);
gboolean			gui_signal_key
					(GtkWidget *widget, GdkEventKey *event, gpointer ptr);

void				gui_signal_entry_launch_control_on_insert
					(GtkEntry *entry, const char *new,
					int length, int *position, gpointer ptr);
void				gui_signal_entry_launch_control_on_delete
					(GtkEntry *entry, int start, int end, gpointer ptr);
void				gui_signal_entry_block_i
					(GtkEntry *entry, const char *new,
					int length, int *position, gpointer ptr);
void				gui_signal_entry_block_f
					(GtkEntry *entry, const char *new,
					int length, int *position, gpointer ptr);

void				gui_signal_parser_select
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_parser_load
					(GtkWidget *widget, gpointer ptr);

void				gui_signal_camera_state_reset
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_camera_state_save
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_camera_state_dialog_response
					(GtkWidget *widget, gpointer ptr);
gboolean			gui_signal_camera_antialiasing
					(GtkWidget *widget, gboolean state, gpointer ptr);
void				gui_signal_camera_filter
					(GtkWidget *widget, gpointer ptr);
gboolean			gui_signal_camera_focus_state
					(GtkWidget *widget, gboolean state, gpointer ptr);
void				gui_signal_camera_focus_auto
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_camera_screen_save
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_camera_screen_dialog_response
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_camera_reset
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_camera_apply
					(GtkWidget *widget, gpointer ptr);

void				gui_signal_scene_edit_combo_changed
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_scene_edit_select
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_scene_edit_reset
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_scene_edit_apply
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_scene_edit_switch_material
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_scene_edit_switch_texture
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_scene_add_switch_material
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_scene_add_switch_texture
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_scene_edit_material_color
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_scene_edit_material_emission
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_scene_edit_scale_changed
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_scene_edit_add
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_scene_edit_remove
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_scene_edit_remove_response_cancel
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_scene_edit_remove_response_yes
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_scene_edit_remove_response_no
					(GtkWidget *widget, gpointer ptr);

void				gui_signal_scene_add_response_cancel
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_scene_add_response_yes
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_scene_add_response_no
					(GtkWidget *widget, gpointer ptr);
gboolean			gui_signal_scene_add_block_destroy
					(GtkWidget *widget, GdkEvent *event, gpointer ptr);
void				gui_signal_scene_add_type_select
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_scene_add_material_color
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_scene_add_material_emission
					(GtkWidget *widget, gpointer ptr);

void				gui_signal_settings_reset
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_settings_apply
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_settings_resize
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_settings_light
					(GtkWidget *widget, gpointer ptr);
gboolean			gui_signal_settings_illumination_state
					(GtkSwitch *widget, gboolean state, gpointer ptr);
void				gui_signal_settings_tracing_rt
					(GtkWidget *widget, gpointer ptr);
void				gui_signal_settings_tracing_rm
					(GtkWidget *widget, gpointer ptr);
gboolean			gui_signal_settings_motion_blur
					(GtkWidget *widget, gboolean state, gpointer ptr);

gboolean			gui_signal_image_click
					(GtkWidget *widget, GdkEventButton *event, gpointer ptr);
gboolean			gui_signal_image_draw
					(GtkWidget *widget, void *cairo, gpointer ptr);

#endif

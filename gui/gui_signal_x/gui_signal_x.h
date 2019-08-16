#ifndef GUI_SIGNAL_H
# define GUI_SIGNAL_H

# include "gui.h"

# define GTK_SIGNAL_SIGNATURE GtkWidget *w, gpointer p

void 				gui_signal_exit
					(GTK_SIGNAL_SIGNATURE);
gboolean			gui_signal_key
					(GtkWidget *widget, GdkEventKey *key, gpointer ptr);

gboolean 			gui_signal_image_click
					(GtkWidget *event_box, GdkEventButton *event, gpointer ptr);

void 				gui_signal_camera_position_x
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_camera_position_y
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_camera_position_z
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_camera_rotation_x
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_camera_rotation_y
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_camera_rotation_z
					(GTK_SIGNAL_SIGNATURE);
gboolean			gui_signal_camera_filter_antialiasing
					(GtkWidget *widget, gboolean state, gpointer ptr);
gboolean			gui_signal_camera_filter_focus
					(GtkWidget *widget, gboolean state, gpointer ptr);
void 				gui_signal_camera_filter_focal_length
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_camera_filter_aperture_size
					(GTK_SIGNAL_SIGNATURE);

void 				gui_signal_scene_edit_select
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

void 				gui_signal_object_edit_sphere_name
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_object_edit_sphere_position_x
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_object_edit_sphere_position_y
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_object_edit_sphere_position_z
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_object_edit_sphere_radius
					(GTK_SIGNAL_SIGNATURE);

void 				gui_signal_object_edit_plane_name
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_object_edit_plane_position_x
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_object_edit_plane_position_y
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_object_edit_plane_position_z
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_object_edit_plane_normal_x
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_object_edit_plane_normal_y
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_object_edit_plane_normal_z
					(GTK_SIGNAL_SIGNATURE);

void 				gui_signal_scene_edit_material_color
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_scene_edit_material_emission
					(GTK_SIGNAL_SIGNATURE);

void				gui_signal_scene_add_response_cancel
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_scene_add_response_yes
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_scene_add_response_no
					(GTK_SIGNAL_SIGNATURE);

void 				gui_signal_scene_add_type_auto
					(GTK_SIGNAL_SIGNATURE);
void 				gui_signal_scene_add_type_manual
					(GTK_SIGNAL_SIGNATURE);

#endif

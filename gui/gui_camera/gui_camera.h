/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_camera.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:27:01 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:27:02 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_CAMERA_H
# define GUI_CAMERA_H

# include "rt_parameters.h"

# include "error_framework.h"
# include "gui_entry.h"
# include "gui_control.h"
# include "camera.h"

# include <gtk/gtk.h>

typedef struct				s_gui_camera
{
	t_rt_bool				connected;
	t_camera				*ptr_camera;
	t_rt_light_mod const	*ptr_light;
	t_gui_control			control;
	GtkEntry				*position_x;
	GtkEntry				*position_y;
	GtkEntry				*position_z;
	GtkEntry				*rotation_x;
	GtkEntry				*rotation_y;
	GtkEntry				*rotation_z;
	GtkDialog				*state_dialog;
	GtkLabel				*state_label;
	GtkDialog				*screen_dialog;
	GtkLabel				*screen_label;
	GtkSwitch				*antialiasing;
	GtkToggleButton			*filter_none;
	GtkWidget				*filter_cartoon_box;
	GtkToggleButton			*filter_cartoon;
	GtkToggleButton			*filter_sepia;
	GtkToggleButton			*filter_stereo;
	GtkSwitch				*focus;
	int						focus_request;
	GtkBox					*focus_box;
	GtkEntry				*focus_focal_length;
	GtkEntry				*focus_aperture_size;
}							t_gui_camera;

t_gui_camera				*gui_camera_new(GtkBuilder *builder);
void						gui_camera_connect(t_gui_camera *gui, ...);
void						gui_camera_delete(t_gui_camera **camera);

void						gui_camera_show(t_gui_camera *gui);
void						gui_camera_apply(t_gui_camera *gui);

#endif

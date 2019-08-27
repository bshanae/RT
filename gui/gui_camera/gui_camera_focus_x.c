#include "gui_camera.h"

void 				gui_camera_focus_enable(t_gui_camera *camera)
{
	gtk_widget_set_opacity(camera->focus_box,  1.);
	gtk_editable_set_editable(GTK_EDITABLE(camera->focus_focal_length), 1);
	gtk_editable_set_editable(GTK_EDITABLE(camera->focus_aperture_size), 1);
}

void 				gui_camera_focus_disable(t_gui_camera *camera)
{
	gtk_widget_set_opacity(camera->focus_box,  0.5);
	gtk_editable_set_editable(GTK_EDITABLE(camera->focus_focal_length), 0);
	gtk_editable_set_editable(GTK_EDITABLE(camera->focus_aperture_size), 0);
}

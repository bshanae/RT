#include "gui_scene_params.h"

void					gui_scene_params_init(
						t_gui_scene_params *gsp,
						GtkBuilder *builder)
{
	gsp->overlay =
		GTK_OVERLAY(gtk_builder_get_object(builder, GSP_OVERLAY));
	gui_scene_param_init(
		&gsp->sphere,
		builder,
		GSP_SPHERE_PARAM,
		GSP_SPHERE_PARENT);
}
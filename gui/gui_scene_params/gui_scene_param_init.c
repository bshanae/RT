#include "gui_scene_params.h"

void					gui_scene_param_init(
						t_gui_scene_param *gsp,
						GtkBuilder *builder,
						const char *param_name,
						const char *parent_name)
{
	gsp->param = GTK_BOX(gtk_builder_get_object(builder, param_name));
	gsp->offscreen_parent =
		GTK_VIEWPORT(gtk_builder_get_object(builder, parent_name));
	gtk_container_remove(
		GTK_CONTAINER(gsp->offscreen_parent),
		GTK_WIDGET(gsp->param));
}
#include "cl_renderer.h"

void				cl_renderer_delete(t_cl_renderer **renderer)
{
	cl_builder_delete(&(*renderer)->builder);
	cl_arg_list_delete(&(*renderer)->args);
	camera_delete(&(*renderer)->data.camera);
	scene_delete(&(*renderer)->data.scene);
	free(*renderer);
	*renderer = NULL;
}
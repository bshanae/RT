#include "cl_renderer.h"

void				cl_renderer_delete(t_cl_renderer **renderer)
{
	cl_builder_delete(&(*renderer)->builder);
	cl_arg_list_delete(&(*renderer)->args);
	camera_delete(&(*renderer)->data.camera);
	texture_delete(&(*renderer)->data.texture);
	scene_delete(&(*renderer)->data.scene);
	free((*renderer)->data.rng_state);
	free(*renderer);
	*renderer = NULL;
}
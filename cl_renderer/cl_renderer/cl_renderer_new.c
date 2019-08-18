#include "cl_renderer.h"

static void				static_data_init(t_cl_renderer *renderer)
{
	int 				i;

	renderer->data.camera =
		camera_new(&renderer->image->width, &renderer->image->height);
	renderer->data.scene = scene_new();
	renderer->data.image = renderer->image->color_buffer;
	renderer->data.settings.sample_count = 0;
	renderer->data.settings.sample_limit = RT_CL_SAMPLES;
	renderer->data.settings.sample_depth = RT_CL_PATH_DEPTH;
	renderer->data.settings.russian_depth = RT_CL_RUSSIAN_DEPTH;
	renderer->data.settings.russian_depth = RT_CL_SRGB;
	renderer->data.settings.light_pb = RT_CL_LIGHT_PB;
	renderer->data.settings.light_explicit = RT_CL_LIGHT_EXPLICIT;
	i = 0;
	renderer->data.rng_state = malloc(sizeof(u_long) *
		renderer->image->width * renderer->image->height);
	srand(21);
	while (i < renderer->image->width * renderer->image->height)
		renderer->data.rng_state[i++] = rand();
}

static void				static_set_args(t_cl_renderer *renderer)
{
	// camera
	cl_arg_list_push(renderer->args, renderer->data.camera,
		sizeof(t_camera), CL_MEM_READ_ONLY);
	// scene
	cl_arg_list_push(renderer->args, renderer->data.scene,
		sizeof(t_scene), CL_MEM_READ_ONLY);
	// image
	cl_arg_list_push(renderer->args, NULL,
		sizeof(int) * renderer->pixel_number, CL_MEM_WRITE_ONLY);
	// settings
	cl_arg_list_push(renderer->args, &renderer->data.settings,
		sizeof(t_cl_renderer_settings), CL_MEM_READ_ONLY);
	//samples
	cl_arg_list_push(renderer->args, NULL,
		sizeof(RT_F4_API) * renderer->pixel_number, CL_MEM_READ_WRITE);
	// rng
	cl_arg_list_push(renderer->args, &renderer->data.rng_state,
		sizeof(u_long) * renderer->pixel_number, CL_MEM_READ_ONLY);
	cl_builder_set_args(renderer->builder, renderer->args);
}

t_cl_renderer			*cl_renderer_new(t_gui_image *image)
{
	t_cl_renderer		*new;

	new = malloc(sizeof(t_cl_renderer));
	new->image = image;
	new->pixel_number = image->width * image->height;
#ifndef RT_NO_OPEN_CL
	new->builder = cl_builder_new();
	new->args = cl_arg_list_new(new->builder->context, new->builder->queue);
#else
	new->builder = NULL;
	new->args = NULL;
#endif
	static_data_init(new);
	static_set_args(new);
	return (new);
}
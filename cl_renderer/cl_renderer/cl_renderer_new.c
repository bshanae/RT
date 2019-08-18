#include "cl_renderer.h"

static void				cl_renderer_set_flags(t_cl_renderer *renderer)
{
	renderer->flags.update_camera = 1;
	renderer->flags.update_scene = 1;
	renderer->flags.update_settings = 1;
}

t_cl_renderer			*cl_renderer_new(t_gui_image *image)
{
	t_cl_renderer		*new;

	new = malloc(sizeof(t_cl_renderer));
	new->image = image;
#ifndef RT_NO_OPEN_CL
	cl_renderer_init_device(new);
	cl_renderer_init_context(new);
	cl_renderer_create_program(new);
	cl_renderer_create_kernel(new);
	cl_renderer_create_queue(new);
#endif
	cl_renderer_init_data(new);
#ifndef RT_NO_OPEN_CL
	cl_renderer_set_arguments(new);
	cl_renderer_set_flags(new);
#endif
	return (new);
}
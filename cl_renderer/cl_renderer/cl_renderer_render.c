#include "cl_renderer.h"

static void			static_run_queue(t_cl_renderer *renderer)
{
	int 			error;

	error = clEnqueueNDRangeKernel(renderer->builder->queue,
		renderer->builder->kernel, 1, NULL,
		&renderer->pixel_number, NULL, 0, NULL, NULL);
	ASSERT(error == 0)
}

void				cl_renderer_render(t_cl_renderer *renderer)
{
#ifndef RT_NO_OPEN_CL
	renderer->data.settings.sample_count++;
	cl_renderer_flag_set(renderer, cl_flag_update_settings);
	cl_renderer_flag_perform(renderer);
	static_run_queue(renderer);
	gtk_image_set_from_pixbuf(renderer->image->image,
		renderer->image->gdk_buffer);
#endif
}

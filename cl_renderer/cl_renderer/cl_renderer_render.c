#include "cl_renderer.h"

static void 		static_pre_queue(t_cl_renderer *renderer)
{
	cl_renderer_flag_perform(renderer);
}

static void 		static_queue(t_cl_renderer *renderer)
{
	int 			error;
	error = clEnqueueNDRangeKernel(renderer->builder->queue,
		renderer->builder->kernel, 1, NULL,
		&renderer->pixel_number, NULL, 0, NULL, NULL);
	ASSERT(error == 0)
}

static void			static_post_queue(t_cl_renderer *renderer)
{
	cl_args_list_read(renderer->args, cl_arg_image);
	if (renderer->data.camera->select_request)
	{
		cl_args_list_read(renderer->args, cl_arg_camera);
		scene_select(renderer->data.scene, renderer->data.camera->select_request_object);
		renderer->data.camera->select_request = 0;
		renderer->data.camera->select_request_object = -1;
		cl_renderer_flag_set(renderer, cl_flag_update_camera);
		cl_renderer_flag_set(renderer, cl_flag_update_scene);
		cl_renderer_flag_set(renderer, cl_flag_reset_samples);
	}
	if (renderer->data.camera->focus_request)
	{
		cl_args_list_read(renderer->args, cl_arg_camera);
		renderer->data.camera->select_request = 0;
		cl_renderer_flag_set(renderer, cl_flag_update_camera);
	}
	if (!renderer->data.settings.motion_blur)
		renderer->data.settings.sample_count++;
	else
		renderer->data.settings.motion_blur_sample_count =
			ft_min(renderer->data.settings.motion_blur_sample_count + 1, RT_CL_SAMPLE_ARRAY_LENGTH);
	cl_renderer_flag_set(renderer, cl_flag_update_settings);
	gtk_image_set_from_pixbuf(renderer->image->image,
		renderer->image->gdk_buffer);
}

void				cl_renderer_render(t_cl_renderer *renderer)
{
#ifndef RT_OPEN_CL_DISABLED
	static_pre_queue(renderer);
	static_queue(renderer);
	static_post_queue(renderer);
#endif
}

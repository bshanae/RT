#include "cl_renderer.h"

static void 		static_pre_queue(t_cl_renderer *renderer)
{
	cl_renderer_flag_perform(renderer);
}

static void 		static_queue(t_cl_renderer *renderer)
{
	int 			error;
	printf("-> queue start : select = %d <-\n", renderer->data.camera->select_request);
	error = clEnqueueNDRangeKernel(renderer->builder->queue,
		renderer->builder->kernel, 1, NULL,
		&renderer->pixel_number, NULL, 0, NULL, NULL);
	printf("-> queue end : select = %d <-\n\n", renderer->data.camera->select_request);
	ASSERT(error == 0)
}

static void			static_post_queue(t_cl_renderer *renderer)
{
	cl_args_list_read(renderer->args, cl_arg_image);
	if (renderer->data.camera->select_request)
	{
		cl_args_list_read(renderer->args, cl_arg_camera);
		renderer->data.camera->select_request = 0;
		scene_choose(renderer->data.scene, renderer->data.camera->select_request_object);
		cl_renderer_flag_set(renderer, cl_flag_update_scene);
		cl_renderer_flag_set(renderer, cl_flag_update_camera);
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
	printf("mb samples = %d\n", renderer->data.settings.motion_blur_sample_count);
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

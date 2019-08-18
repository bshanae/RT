#include "cl_renderer.h"

void						cl_renderer_flag_set(
							t_cl_renderer *renderer,
							t_cl_renderer_flag flag)
{
	if (flag == cl_flag_update_camera)
		renderer->flags.update_camera = 1;
	else if (flag == cl_flag_update_scene)
		renderer->flags.update_scene = 1;
	else if (flag == cl_flag_update_settings)
		renderer->flags.update_settings = 1;
	else if (flag == cl_flag_reset_samples)
		renderer->flags.reset_samples = 1;
	renderer->flags.summary = 1;
}

void						cl_renderer_flag_perform(t_cl_renderer *renderer)
{
	if (!renderer->flags.summary);
	else if (renderer->flags.update_camera)
		renderer->args->array[cl_arg_camera].update_need = 1;
	else if (renderer->flags.update_scene)
		renderer->args->array[cl_arg_scene].update_need = 1;
	else if (renderer->flags.update_settings)
		renderer->args->array[cl_arg_settings].update_need = 1;
	else if (renderer->flags.reset_samples)
	{
		renderer->data.settings.sample_count = 0;
		renderer->args->array[cl_arg_settings].update_need = 1;
	}
	cl_arg_list_update(renderer->args);
	ft_bzero(&renderer->flags, sizeof(t_cl_renderer_flag_list));
}
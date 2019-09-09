#include "cl_renderer.h"

void				cl_renderer_object_move
					(t_cl_renderer *renderer, t_movement movement)
{
	t_object		*object;
	u_int			flag;
	RT_F4_API		step;
	RT_F4_API		*ptr;

	object = renderer->data.scene->objects +
		renderer->data.camera->select_request_object;
	flag = object_flag_get(object);
	if (flag & RT_OBJECT_MOVE_NONE)
		return ;
	ptr = (RT_F4_API *)object->data;
	step = camera_get_step(renderer->data.camera, movement);
	step = f4_mul(step, RT_OBJECT_MOVE_VALUE);
	if ((flag & RT_OBJECT_MOVE_A) || (flag & RT_OBJECT_MOVE_B))
		ptr[0] = f4_add(ptr[0], step);
	if (flag & RT_OBJECT_MOVE_B)
		ptr[1] = f4_add(ptr[1], step);
	cl_renderer_flag_set(renderer, cl_flag_update_scene);
	cl_renderer_flag_set(renderer, cl_flag_reset_samples);
}

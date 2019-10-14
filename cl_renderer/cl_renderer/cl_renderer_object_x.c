/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_renderer_object_move.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:03:06 by ashari            #+#    #+#             */
/*   Updated: 2019/10/14 12:56:07 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_renderer.h"

#define MESSAGE	"Renderer : Can't move pair, because it's recursive"

static void			static_move_one(
					t_scene *scene, t_object *object, RT_F4_API step)
{
	u_int			flag;
	RT_F4_API		*ptr;
	t_object_pair	*pair;

	flag = object_flag_get(object);
	ptr = (RT_F4_API *)object->data;
	if ((flag & RT_OBJECT_MOVE_A) || (flag & RT_OBJECT_MOVE_B))
		ptr[0] = f4_add(ptr[0], step);
	if (flag & RT_OBJECT_MOVE_B)
		ptr[1] = f4_add(ptr[1], step);
	if (flag & RT_OBJECT_MOVE_C)
	{
		pair = (t_object_pair *)object->data;
		if (object_flag_get(scene->objects + pair->first_id) & RT_OBJECT_PAIR)
			rt_raise_warning(MESSAGE);
		else
			static_move_one(scene, scene->objects + pair->first_id, step);
	}
}

void				cl_renderer_object_move(
					t_cl_renderer *renderer, t_rt_movement movement)
{
	t_object		*object;
	RT_F4_API		step;

	object = renderer->data.scene->objects + renderer->data.scene->selected_id;
	step = camera_get_step(renderer->data.camera, movement);
	step = f4_mul(step, RT_OBJECT_MOVE_VALUE);
	static_move_one(renderer->data.scene, object, step);
	cl_renderer_flag_set(renderer, cl_flag_update_scene);
	cl_renderer_flag_set(renderer, cl_flag_reset_samples);
}

void				cl_renderer_object_select(
					t_cl_renderer *renderer, int id)
{
	scene_select(renderer->data.scene, id);
	cl_renderer_flag_set(renderer, cl_flag_update_scene);
	cl_renderer_flag_set(renderer, cl_flag_reset_samples);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_common_check_mod.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:13:47 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/14 13:13:48 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_common.h"

#ifndef RT_DOUBLE

int					gui_scene_common_check_mod
	(t_gui_scene_common *gui, t_object *object)
{
	const UINT		flag = object_flag_get(object);

	if (object->type == object_type_moebius)
		return (0);
	if (flag & RT_OBJECT_LIGHT && *gui->ptr_light != rt_light_basic)
		return (0);
	return ((int)(flag & *gui->ptr_scene->tracing_mod_mask));
}

#else

int					gui_scene_common_check_mod
	(t_gui_scene_common *gui, t_object *object)
{
	const UINT		flag = object_flag_get(object);

	if (flag & RT_OBJECT_LIGHT && *gui->ptr_light != rt_light_basic)
		return (0);
	return ((int)(flag & *gui->ptr_scene->tracing_mod_mask));
}

#endif

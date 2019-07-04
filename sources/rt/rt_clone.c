/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_clone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:12:10 by ashari            #+#    #+#             */
/*   Updated: 2019/07/02 11:57:08 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				rt_clone(t_rt *me)
{
	int i;

	if (!(me->clone = (t_rt *)malloc(sizeof(t_rt))))
		exit(21);
	me->clone->mlx_ptr = me->mlx_ptr;
	me->clone->win_ptr = me->win_ptr;
	me->clone->img_ptr = me->img_ptr;
	me->clone->img_data = me->img_data;
	i = 0;
	while (i < me->scenes.length)
	{
		me->clone->scenes.data[i] = scene_new();
		*me->clone->scenes.data[i] = *me->scenes.data[i];
		i++;
	}
	me->clone->scenes.length = me->scenes.length;
	me->clone->scenes.index = 0;
	me->clone->scenes.current = &me->clone->scenes.data[0];
	me->clone->ctrl_light.is_on = 0;
	me->clone->ctrl_light.index = 0;
	me->clone->ctrl_shape.is_on = 0;
	me->clone->ctrl_shape.index = 0;
	me->clone->clone = NULL;
	me->clone->open_cl = NULL;
}

void				rt_reset(t_rt **me)
{
	t_rt			*old;

	old = *me;
	*me = (*me)->clone;
	(*me)->open_cl = old->open_cl;
	rt_delete(&old);
	rt_clone(*me);
}

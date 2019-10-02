/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_common_gen_name.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:43:02 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:43:04 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_common.h"

void				gui_scene_common_gen_name
	(t_gui_scene_common *scene, t_object *object)
{
	int				i;
	static int		id[object_type_end];
	char			*temp;

	if (scene->reset_generator)
	{
		i = 0;
		while (i < object_type_end)
			id[i++] = 0;
		scene->reset_generator = rt_false;
		return ;
	}
	if (!object)
	{
		rt_assert(0, "GUI name generator: Object is NULL");
		return ;
	}
	ft_strcpy(object->name, object_translate(object->type));
	temp = ft_itoa(id[object->type]++);
	ft_strcat(object->name, " no. ");
	ft_strcat(object->name, temp);
	free(temp);
}

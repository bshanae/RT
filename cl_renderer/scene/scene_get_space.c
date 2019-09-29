/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_get_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:22:37 by ashari            #+#    #+#             */
/*   Updated: 2019/09/29 15:22:38 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_object			*scene_get_space(t_scene *scene)
{
	if (scene->objects_length < RT_SCENE_CAPACITY)
		return (scene->objects + scene->objects_length++);
	return (NULL);
}

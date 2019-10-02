/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_add_init_sphere.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:36:01 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:36:02 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_add.h"

void					gui_scene_add_init_sphere
	(t_gui_scene_add *add, GtkBuilder *builder)
{
	t_gui_init_sphere	init;

	ft_strcpy(init.position_x, "object_add_sphere_position_x");
	ft_strcpy(init.position_y, "object_add_sphere_position_y");
	ft_strcpy(init.position_z, "object_add_sphere_position_z");
	ft_strcpy(init.radius, "object_add_sphere_radius");
	add->sphere = gui_object_sphere_init(&init, builder);
}

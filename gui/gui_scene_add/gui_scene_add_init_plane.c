/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_add_init_plane.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:35:30 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:35:39 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_add.h"

void					gui_scene_add_init_plane
	(t_gui_scene_add *add, GtkBuilder *builder)
{
	t_gui_init_plane	init;

	ft_strcpy(init.position_x, "object_add_plane_position_x");
	ft_strcpy(init.position_y, "object_add_plane_position_y");
	ft_strcpy(init.position_z, "object_add_plane_position_z");
	ft_strcpy(init.normal_x, "object_add_plane_normal_x");
	ft_strcpy(init.normal_y, "object_add_plane_normal_y");
	ft_strcpy(init.normal_z, "object_add_plane_normal_z");
	add->plane = gui_object_plane_init(&init, builder);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_edit_init_plane.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:15:57 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:16:04 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_edit.h"

void					gui_scene_edit_init_plane
	(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_plane	init;

	ft_strcpy(init.position_x, "object_edit_plane_position_x");
	ft_strcpy(init.position_y, "object_edit_plane_position_y");
	ft_strcpy(init.position_z, "object_edit_plane_position_z");
	ft_strcpy(init.normal_x, "object_edit_plane_normal_x");
	ft_strcpy(init.normal_y, "object_edit_plane_normal_y");
	ft_strcpy(init.normal_z, "object_edit_plane_normal_z");
	edit->plane = gui_object_plane_init(&init, builder);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_edit_init_sphere.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:16:19 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:16:19 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_edit.h"

void					gui_scene_edit_init_sphere
	(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_sphere	init;

	ft_strcpy(init.position_x, "object_edit_sphere_position_x");
	ft_strcpy(init.position_y, "object_edit_sphere_position_y");
	ft_strcpy(init.position_z, "object_edit_sphere_position_z");
	ft_strcpy(init.radius, "object_edit_sphere_radius");
	edit->sphere = gui_object_sphere_init(&init, builder);
}

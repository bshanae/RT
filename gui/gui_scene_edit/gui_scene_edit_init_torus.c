/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_edit_init_torus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:16:32 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:16:32 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_edit.h"

void					gui_scene_edit_init_torus
	(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_torus	init;

	ft_strcpy(init.position_x, "object_edit_torus_position_x");
	ft_strcpy(init.position_y, "object_edit_torus_position_y");
	ft_strcpy(init.position_z, "object_edit_torus_position_z");
	ft_strcpy(init.radius, "object_edit_torus_radius");
	ft_strcpy(init.width, "object_edit_torus_width");
	edit->torus = gui_object_torus_init(&init, builder);
}

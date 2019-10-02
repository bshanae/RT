/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_add_init_torus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:36:24 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:36:36 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_add.h"

void					gui_scene_add_init_torus
	(t_gui_scene_add *edit, GtkBuilder *builder)
{
	t_gui_init_torus	init;

	ft_strcpy(init.position_x, "object_add_torus_position_x");
	ft_strcpy(init.position_y, "object_add_torus_position_y");
	ft_strcpy(init.position_z, "object_add_torus_position_z");
	ft_strcpy(init.radius, "object_add_torus_radius");
	ft_strcpy(init.width, "object_add_torus_width");
	edit->torus = gui_object_torus_init(&init, builder);
}

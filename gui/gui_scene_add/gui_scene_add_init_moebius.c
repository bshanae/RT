/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_add_init_moebius.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:33:45 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:33:45 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_add.h"

void					gui_scene_add_init_moebius
	(t_gui_scene_add *edit, GtkBuilder *builder)
{
	t_gui_init_moebius	init;

	ft_strcpy(init.position_x, "object_add_moebius_position_x");
	ft_strcpy(init.position_y, "object_add_moebius_position_y");
	ft_strcpy(init.position_z, "object_add_moebius_position_z");
	ft_strcpy(init.radius, "object_add_moebius_radius");
	ft_strcpy(init.width, "object_add_moebius_width");
	edit->moebius = gui_object_moebius_init(&init, builder);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_add_init_explosion.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:27:59 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:27:59 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_add.h"

void						gui_scene_add_init_explosion
	(t_gui_scene_add *add, GtkBuilder *builder)
{
	t_gui_init_explosion	init;

	ft_strcpy(init.position_x, "object_add_explosion_position_x");
	ft_strcpy(init.position_y, "object_add_explosion_position_y");
	ft_strcpy(init.position_z, "object_add_explosion_position_z");
	ft_strcpy(init.radius, "object_add_explosion_radius");
	ft_strcpy(init.noise, "object_add_explosion_noise");
	add->explosion = gui_object_explosion_init(&init, builder);
}

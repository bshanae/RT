/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_edit_init_explosion.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:10:55 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:11:05 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_edit.h"

void						gui_scene_edit_init_explosion
	(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_explosion	init;

	ft_strcpy(init.position_x, "object_edit_explosion_position_x");
	ft_strcpy(init.position_y, "object_edit_explosion_position_y");
	ft_strcpy(init.position_z, "object_edit_explosion_position_z");
	ft_strcpy(init.radius, "object_edit_explosion_radius");
	ft_strcpy(init.noise, "object_edit_explosion_noise");
	edit->explosion = gui_object_explosion_init(&init, builder);
}

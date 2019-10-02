/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_add_init_box.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:26:06 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:26:08 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_add.h"

void				gui_scene_add_init_box
	(t_gui_scene_add *edit, GtkBuilder *builder)
{
	t_gui_init_box	init;

	ft_strcpy(init.position_x, "object_add_box_position_x");
	ft_strcpy(init.position_y, "object_add_box_position_y");
	ft_strcpy(init.position_z, "object_add_box_position_z");
	ft_strcpy(init.size_x, "object_add_box_size_x");
	ft_strcpy(init.size_y, "object_add_box_size_y");
	ft_strcpy(init.size_z, "object_add_box_size_z");
	edit->box = gui_object_box_init(&init, builder);
}

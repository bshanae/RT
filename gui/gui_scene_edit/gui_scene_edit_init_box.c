/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_edit_init_box.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:02:32 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:02:34 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_edit.h"

void				gui_scene_edit_init_box
	(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_box	init;

	ft_strcpy(init.position_x, "object_edit_box_position_x");
	ft_strcpy(init.position_y, "object_edit_box_position_y");
	ft_strcpy(init.position_z, "object_edit_box_position_z");
	ft_strcpy(init.size_x, "object_edit_box_size_x");
	ft_strcpy(init.size_y, "object_edit_box_size_y");
	ft_strcpy(init.size_z, "object_edit_box_size_z");
	edit->box = gui_object_box_init(&init, builder);
}

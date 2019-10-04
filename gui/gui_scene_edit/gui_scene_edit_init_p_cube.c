/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_edit_init_p_cube.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:15:11 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:15:12 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_edit.h"

void					gui_scene_edit_init_p_cube
	(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_p_cube	init;

	ft_strcpy(init.position_x, "object_edit_perforated_cube_position_x");
	ft_strcpy(init.position_y, "object_edit_perforated_cube_position_y");
	ft_strcpy(init.position_z, "object_edit_perforated_cube_position_z");
	ft_strcpy(init.iterations, "object_edit_perforated_cube_iterations");
	edit->p_cube = gui_object_p_cube_init(&init, builder);
}

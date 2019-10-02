/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_add_init_p_cube.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:34:19 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:34:19 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_add.h"

void					gui_scene_add_init_p_cube
	(t_gui_scene_add *add, GtkBuilder *builder)
{
	t_gui_init_p_cube	init;

	ft_strcpy(init.position_x, "object_add_perforated_cube_position_x");
	ft_strcpy(init.position_y, "object_add_perforated_cube_position_y");
	ft_strcpy(init.position_z, "object_add_perforated_cube_position_z");
	ft_strcpy(init.iterations, "object_add_perforated_cube_iterations");
	add->p_cube = gui_object_p_cube_init(&init, builder);
}

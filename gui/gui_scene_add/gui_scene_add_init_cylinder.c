/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_add_init_cylinder.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:27:42 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:27:42 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_add.h"

void					gui_scene_add_init_cylinder
	(t_gui_scene_add *add, GtkBuilder *builder)
{
	t_gui_init_cylinder	init;

	ft_strcpy(init.top_x, "object_add_cylinder_top_x");
	ft_strcpy(init.top_y, "object_add_cylinder_top_y");
	ft_strcpy(init.top_z, "object_add_cylinder_top_z");
	ft_strcpy(init.bottom_x, "object_add_cylinder_bottom_x");
	ft_strcpy(init.bottom_y, "object_add_cylinder_bottom_y");
	ft_strcpy(init.bottom_z, "object_add_cylinder_bottom_z");
	ft_strcpy(init.radius, "object_add_cylinder_radius");
	add->cylinder = gui_object_cylinder_init(&init, builder);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_add_init_paraboloid.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:34:37 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:34:37 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_add.h"

void						gui_scene_add_init_paraboloid
	(t_gui_scene_add *edit, GtkBuilder *builder)
{
	t_gui_init_paraboloid	init;

	ft_strcpy(init.extremum_x, "object_add_paraboloid_extremum_x");
	ft_strcpy(init.extremum_y, "object_add_paraboloid_extremum_y");
	ft_strcpy(init.extremum_z, "object_add_paraboloid_extremum_z");
	ft_strcpy(init.axis_x, "object_add_paraboloid_axis_x");
	ft_strcpy(init.axis_y, "object_add_paraboloid_axis_y");
	ft_strcpy(init.axis_z, "object_add_paraboloid_axis_z");
	ft_strcpy(init.radius, "object_add_paraboloid_radius");
	edit->paraboloid = gui_object_paraboloid_init(&init, builder);
}

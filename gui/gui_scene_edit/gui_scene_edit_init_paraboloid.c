/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_edit_init_paraboloid.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:15:41 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:15:41 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_edit.h"

void						gui_scene_edit_init_paraboloid
	(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_paraboloid	init;

	ft_strcpy(init.extremum_x, "object_edit_paraboloid_extremum_x");
	ft_strcpy(init.extremum_y, "object_edit_paraboloid_extremum_y");
	ft_strcpy(init.extremum_z, "object_edit_paraboloid_extremum_z");
	ft_strcpy(init.axis_x, "object_edit_paraboloid_axis_x");
	ft_strcpy(init.axis_y, "object_edit_paraboloid_axis_y");
	ft_strcpy(init.axis_z, "object_edit_paraboloid_axis_z");
	ft_strcpy(init.radius, "object_edit_paraboloid_radius");
	edit->paraboloid = gui_object_paraboloid_init(&init, builder);
}

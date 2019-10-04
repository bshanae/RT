/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_edit_init_julia.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:11:16 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:11:16 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_edit.h"

void					gui_scene_edit_init_julia
	(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_julia	init;

	ft_strcpy(init.iterations, "object_edit_julia_iterations");
	ft_strcpy(init.value_x, "object_edit_julia_value_x");
	ft_strcpy(init.value_y, "object_edit_julia_value_y");
	ft_strcpy(init.value_z, "object_edit_julia_value_z");
	ft_strcpy(init.value_w, "object_edit_julia_value_w");
	edit->julia = gui_object_julia_init(&init, builder);
}

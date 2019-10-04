/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_edit_init_mandelbulb.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:12:22 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:12:32 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_edit.h"

void						gui_scene_edit_init_mandelbulb
	(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_mandelbulb	init;

	ft_strcpy(init.iterations, "object_edit_mandelbulb_iterations");
	ft_strcpy(init.power, "object_edit_mandelbulb_power");
	edit->mandelbulb = gui_object_mandelbulb_init(&init, builder);
}

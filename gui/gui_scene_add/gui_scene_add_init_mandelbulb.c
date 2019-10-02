/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_add_init_mandelbulb.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:30:08 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:30:16 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_add.h"

void						gui_scene_add_init_mandelbulb
	(t_gui_scene_add *edit, GtkBuilder *builder)
{
	t_gui_init_mandelbulb	init;

	ft_strcpy(init.iterations, "object_add_mandelbulb_iterations");
	ft_strcpy(init.power, "object_add_mandelbulb_power");
	edit->mandelbulb = gui_object_mandelbulb_init(&init, builder);
}

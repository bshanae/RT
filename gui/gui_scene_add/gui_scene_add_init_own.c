/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_add_init_own.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:34:04 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:34:04 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_add.h"

void				gui_scene_add_init_own
	(t_gui_scene_add *add, GtkBuilder *builder)
{
	add->dialog = RT_GUI_GET(builder, "dialog");
	add->name = RT_GUI_GET(builder, "scene_add_name");
	add->type_combo = RT_GUI_GET(builder, "scene_add_type_combo");
	add->stack = RT_GUI_GET(builder, "scene_add_stack");
}

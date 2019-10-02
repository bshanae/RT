/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_add_init_csg.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:27:10 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:27:30 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_add.h"

void				gui_scene_add_init_csg
	(t_gui_scene_add *add, GtkBuilder *builder)
{
	t_gui_init_pair	init;

	ft_strcpy(init.first_combo, "object_add_csg_positive");
	ft_strcpy(init.second_combo, "object_add_csg_negative");
	ft_strcpy(init.first_list, "scene_csg_list");
	ft_strcpy(init.second_list, "scene_csg_list");
	add->csg = gui_object_pair_init(&init, builder);
}

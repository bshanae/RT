/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_edit_init_csg.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:03:19 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:03:19 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_edit.h"

void				gui_scene_edit_init_csg
	(t_gui_scene_edit *edit, GtkBuilder *builder)
{
	t_gui_init_pair	init;

	ft_strcpy(init.first_combo, "object_edit_csg_positive");
	ft_strcpy(init.second_combo, "object_edit_csg_negative");
	ft_strcpy(init.first_list, "scene_csg_list");
	ft_strcpy(init.second_list, "scene_csg_list");
	edit->csg = gui_object_pair_init(&init, builder);
}

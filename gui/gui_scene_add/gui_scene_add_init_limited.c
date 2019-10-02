/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_add_init_limited.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:29:49 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:29:49 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_add.h"

void				gui_scene_add_init_limited
	(t_gui_scene_add *add, GtkBuilder *builder)
{
	t_gui_init_pair	init;

	ft_strcpy(init.first_combo, "object_add_limited_main");
	ft_strcpy(init.second_combo, "object_add_limited_limit");
	ft_strcpy(init.first_list, "scene_limited_main_list");
	ft_strcpy(init.second_list, "scene_limited_limit_list");
	add->limited = gui_object_pair_init(&init, builder);
}

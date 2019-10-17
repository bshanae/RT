/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_common_update_x_b.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:50:39 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_common.h"

void				gui_scene_common_update_types(t_gui_scene_common *gui)
{
	GtkTreeIter		iter_list;
	t_object_type	iter_type;
	t_object		temp;

	rt_assert_critical(gui->connected, "GUI Common : Not connected");
	gtk_list_store_clear(gui->types);
	iter_type = 0;
	while (iter_type < object_type_end)
	{
		temp.type = iter_type;
		if (gui_scene_common_check_mod(gui, &temp))
		{
			gtk_list_store_append(gui->types, &iter_list);
			gtk_list_store_set(gui->types, &iter_list,
				gui_list_id, iter_type,
				gui_list_name, object_translate(iter_type), -1);
		}
		iter_type++;
	}
}

void				gui_scene_common_update_textures(t_gui_scene_common *gui)
{
	GtkTreeIter		iter_list;
	int				i;

	rt_assert_critical(gui->connected, "GUI Common : Not connected");
	gtk_list_store_clear(gui->textures);
	gtk_list_store_append(gui->textures, &iter_list);
	gtk_list_store_set(gui->textures, &iter_list,
		gui_list_id, -1,
		gui_list_name, "None", -1);
	i = 0;
	while (i <= gui->ptr_scene->texture.textures_number)
	{
		gtk_list_store_append(gui->textures, &iter_list);
		gtk_list_store_set(gui->textures, &iter_list,
			gui_list_id, i,
			gui_list_name, gui->ptr_scene->texture.name[i], -1);
		i++;
	}
}

void				gui_scene_common_update_background
	(t_gui_scene_common *gui)
{
	t_rt_background	i;
	GtkTreeIter		iter;

	i = 0;
	gtk_list_store_clear(gui->full);
	while (i < rt_background_end)
	{
		gtk_list_store_append(gui->background, &iter);
		gtk_list_store_set(gui->background, &iter,
			gui_list_id, i,
			gui_list_name, rt_background_translate(i), -1);
		i++;
	}
}

void				gui_scene_common_update_all(t_gui_scene_common *gui)
{
	rt_assert_critical(gui->connected, "GUI Common : Not connected");
	gui->reset_generator = rt_true;
	gui_scene_common_gen_name(gui, NULL);
	gui_scene_common_update_full(gui);
	gui_scene_common_update_limited(gui);
	gui_scene_common_update_csg(gui);
	gui_scene_common_update_textures(gui);
	gui_scene_common_update_types(gui);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_common_update_x.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:43:42 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_common.h"

void				gui_scene_common_update_full(t_gui_scene_common *gui)
{
	int				i;

	rt_assert_critical(gui->connected, "GUI Common : Not connected");
	i = 0;
	gtk_list_store_clear(gui->full);
	while (i < gui->ptr_scene->objects_length)
	{
		if (!gui->ptr_scene->objects[i].name[0])
			gui_scene_common_gen_name(gui, gui->ptr_scene->objects + i);
		if (gui_scene_common_check_mod(gui, gui->ptr_scene->objects + i))
			gui_scene_common_add_to_list(gui->full,
				gui->ptr_scene->objects + i);
		i++;
	}
}

static int			static_prepare_limited(t_gui_scene_common *gui)
{
	t_object		temp;

	rt_assert_critical(gui->connected, "GUI Common : Not connected");
	if (*gui->ptr_scene->tracing_mod_mask == RT_OBJECT_RM)
		return (0);
	gtk_list_store_clear(gui->limited_main);
	gtk_list_store_clear(gui->limited_limit);
	ft_strcpy(temp.name, "None");
	temp.id = -1;
	gui_scene_common_add_to_list(gui->limited_main, &temp);
	gui_scene_common_add_to_list(gui->limited_limit, &temp);
	return (1);
}

void				gui_scene_common_update_limited(t_gui_scene_common *gui)
{
	GtkTreeModel	*model;
	int				i;
	GtkTreeIter		iter_full;

	if (!static_prepare_limited(gui))
		return ;
	model = GTK_TREE_MODEL(gui->full);
	if (!gtk_tree_model_get_iter_first(model, &iter_full))
		return ;
	while (1)
	{
		gtk_tree_model_get(model, &iter_full, gui_list_id, &i, -1);
		if (object_flag_get(gui->ptr_scene->objects + i) & RT_OBJECT_LIMITABLE)
			gui_scene_common_add_to_list(gui->limited_main,
				gui->ptr_scene->objects + i);
		else if (object_flag_get(gui->ptr_scene->objects + i)
			& RT_OBJECT_LIMITING)
			gui_scene_common_add_to_list(gui->limited_limit,
				gui->ptr_scene->objects + i);
		if (!gtk_tree_model_iter_next(model, &iter_full))
			break ;
	}
}

void				gui_scene_common_update_csg(t_gui_scene_common *gui)
{
	GtkTreeModel	*model;
	int				i;
	GtkTreeIter		iter_full;
	t_object		temp;

	rt_assert_critical(gui->connected, "GUI Common : Not connected");
	model = GTK_TREE_MODEL(gui->full);
	if (*gui->ptr_scene->tracing_mod_mask == RT_OBJECT_RT)
		return ;
	if (!gtk_tree_model_get_iter_first(model, &iter_full))
		return ;
	gtk_list_store_clear(gui->csg);
	ft_strcpy(temp.name, "None");
	temp.id = -1;
	gui_scene_common_add_to_list(gui->csg, &temp);
	while (1)
	{
		gtk_tree_model_get(model, &iter_full, gui_list_id, &i, -1);
		if (object_flag_get(gui->ptr_scene->objects + i) & RT_OBJECT_CSG)
			gui_scene_common_add_to_list(gui->csg, gui->ptr_scene->objects + i);
		i++;
		if (!gtk_tree_model_iter_next(model, &iter_full))
			break ;
	}
}

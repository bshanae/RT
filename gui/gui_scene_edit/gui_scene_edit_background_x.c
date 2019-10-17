/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_edit_background_x.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 12:54:11 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_edit.h"

void				gui_scene_edit_background_get
	(t_gui_scene_edit *edit, t_scene *scene)
{
	GtkTreeModel	*model;
	int				i;
	GtkTreeIter		iter;

	model = GTK_TREE_MODEL(edit->common->background);
	if (!gtk_tree_model_get_iter_first(model, &iter))
		return ;
	while (1)
	{
		gtk_tree_model_get(model, &iter, gui_list_id, &i, -1);
		if (i == scene->background)
		{
			gtk_combo_box_set_active_iter(edit->background_combo, &iter);
			return ;
		}
		if (!gtk_tree_model_iter_next(model, &iter))
			break ;
	}
	rt_raise_warning("GUI Editor : Background id not found");
}

int					gui_scene_edit_background_read_value
	(t_gui_scene_edit *edit)
{
	GtkTreeIter		iter;
	t_rt_background	value;

	value = -1;
	if (gtk_combo_box_get_active_iter(edit->background_combo, &iter))
		gtk_tree_model_get(GTK_TREE_MODEL(edit->common->background), &iter,
			gui_list_id, &value, -1);
	else
		rt_raise_error("GUI Editor : No background selected\n");
	return (value);
}

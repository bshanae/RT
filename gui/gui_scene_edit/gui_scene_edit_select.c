/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_edit_select.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:17:01 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_edit.h"

void				gui_scene_edit_select
	(t_gui_scene_edit *edit, t_scene *scene)
{
	GtkTreeModel	*model;
	GtkTreeIter		iter;
	int				id;

	rt_assert_critical(edit->common != NULL, "GUI Editor : Common is NULL");
	if (scene->selected_id == -1)
		return ;
	edit->current_id = scene->selected_id;
	gtk_widget_set_sensitive(edit->remove_button, TRUE);
	model = GTK_TREE_MODEL(edit->common->full);
	if (!gtk_tree_model_get_iter_first(model, &iter))
		return ;
	while (1)
	{
		gtk_tree_model_get(model, &iter, gui_list_id, &id, -1);
		if (id == scene->selected_id)
			break ;
		if (!gtk_tree_model_iter_next(model, &iter))
		{
			rt_raise_warning("GUI Editor : Object not found in common");
			return ;
		}
	}
	gtk_tree_selection_select_iter(edit->selection, &iter);
}

void				gui_scene_edit_unselect(t_gui_scene_edit *edit)
{
	edit->current_id = -1;
	gtk_widget_set_sensitive(edit->remove_button, FALSE);
	gui_material_hide(&edit->material);
	gtk_widget_hide(GTK_WIDGET(edit->info));
	gtk_tree_selection_unselect_all(edit->selection);
	gui_control_hide(&edit->control);
}

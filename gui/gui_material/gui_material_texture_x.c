/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_material_texture_x.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:49:38 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_material.h"

void				gui_material_texture_enable(t_gui_material *material)
{
	material->texture_state = rt_on;
	gtk_stack_set_visible_child_name(material->switcher_stack, "show");
}

void				gui_material_texture_disable(t_gui_material *material)
{
	material->texture_state = rt_off;
	gtk_stack_set_visible_child_name(material->switcher_stack, "hide");
	gui_material_switch_mod(material, gui_material_material);
}

void				gui_material_texture_get
	(t_gui_material *material, int id)
{
	GtkTreeModel	*model;
	int				i;
	GtkTreeIter		iter;

	model = GTK_TREE_MODEL(material->texture_list);
	if (!gtk_tree_model_get_iter_first(model, &iter))
		return ;
	while (1)
	{
		gtk_tree_model_get(model, &iter, gui_list_id, &i, -1);
		if (i == id)
		{
			gtk_combo_box_set_active_iter(material->texture_combo, &iter);
			return ;
		}
		if (!gtk_tree_model_iter_next(model, &iter))
			break ;
	}
	rt_raise_warning("GUI Material : Texture not found (id = %d)", id);
}

void				gui_material_texture_set
	(t_gui_material *material, int *id)
{
	GtkTreeIter		iter;

	gtk_combo_box_get_active_iter(material->texture_combo, &iter);
	gtk_tree_model_get(GTK_TREE_MODEL(material->texture_list),
		&iter, gui_list_id, id, -1);
}

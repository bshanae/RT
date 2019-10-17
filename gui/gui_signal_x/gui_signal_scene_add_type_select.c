/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_scene_add_type_select.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:51:39 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_signal_x.h"

void				gui_signal_scene_add_type_select
	(GtkWidget *widget, gpointer ptr)
{
	t_gui			*gui;
	GtkTreeIter		iter;
	t_gui_scene_add	*add;

	gui = (t_gui *)ptr;
	add = gui->scene->add;
	rt_assert_critical(add->common != NULL,
		"GUI Creator : gui_scene_common is NULL");
	if (gui->scene->common->update_process)
		return ;
	if (!gtk_combo_box_get_active_iter(add->type_combo, &iter))
		return (rt_raise_warning("GUI Creator : No active type"));
	gtk_tree_model_get(GTK_TREE_MODEL(add->common->types), &iter,
		gui_list_id, &add->current_type, -1);
	gtk_stack_set_visible_child_name(add->stack,
		object_translate(add->current_type));
	add->temp_object.type = add->current_type;
	gui_material_set(&add->material, &add->temp_object.material,
		&add->temp_object.texture_id);
	gui_material_prepare(&add->material, &add->temp_object);
}

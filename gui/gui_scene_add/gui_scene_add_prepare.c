/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_add_prepare.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:38:11 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:38:13 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_add.h"

void				static_default_object(t_object *object)
{
	object->type = object_type_sphere;
	object->material = MATERIAL_WHITE;
	object->texture_id = -1;
}

void				gui_scene_add_prepare(t_gui_scene_add *add)
{
	CHAR_REF		str;
	GtkTreeIter		iter;
	GtkTreeModel	*model;
	t_object_type	type;

	str = gui_scene_add_gen_name(add);
	gtk_entry_set_placeholder_text(add->name, str);
	free((void *)str);
	static_default_object(&add->temp_object);
	gui_material_prepare(&add->material, &add->temp_object);
	gui_material_get(&add->material, &add->temp_object.material,
		&add->temp_object.texture_id);
	model = GTK_TREE_MODEL(add->common->types);
	if (!gtk_tree_model_get_iter_first(model, &iter))
		return ;
	while (1)
	{
		gtk_tree_model_get(model, &iter, gui_list_column_id, &type, -1);
		if (type == object_type_sphere)
			break ;
		if (!gtk_tree_model_iter_next(model, &iter))
			return ;
	}
	gtk_combo_box_set_active_iter(add->type_combo, &iter);
}

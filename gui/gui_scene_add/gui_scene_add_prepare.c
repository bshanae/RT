/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_add_prepare.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:38:11 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_add.h"

void				static_default_object(t_object *object)
{
	object->type = object_type_sphere;
	object->material = MATERIAL_WHITE;
	object->texture_id = -1;
}

void				static_prepare_material(t_gui_scene_add *add)
{
	gui_material_prepare(&add->material, &add->temp_object);
	gui_material_get(&add->material, &add->temp_object.material,
		&add->temp_object.texture_id);
}

static void			static_clear_a(t_gui_scene_add *add)
{
	if (*add->common->ptr_scene->tracing_mod == rt_tracing_rt)
	{
		gui_object_sphere_clear(&add->sphere);
		gui_object_plane_clear(&add->plane);
		gui_object_cone_clear(&add->cone);
		gui_object_cylinder_clear(&add->cylinder);
		gui_object_box_clear(&add->box);
		gui_object_paraboloid_clear(&add->paraboloid);
		gui_object_moebius_clear(&add->moebius);
		gui_object_pair_clear(&add->limited);
	}
	if (*add->common->ptr_scene->tracing_mod == rt_tracing_rm)
	{
		gui_object_sphere_clear(&add->sphere);
		gui_object_plane_clear(&add->plane);
		gui_object_box_clear(&add->box);
		gui_object_torus_clear(&add->torus);
		gui_object_mandelbulb_clear(&add->mandelbulb);
		gui_object_julia_clear(&add->julia);
		gui_object_p_cube_clear(&add->p_cube);
		gui_object_explosion_clear(&add->explosion);
		gui_object_pair_clear(&add->csg);
	}
}

static void			static_clear_b(t_gui_scene_add *add)
{
	if (*add->common->ptr_light == rt_light_basic)
	{
		gui_object_light_point_clear(&add->light_point);
		gui_object_light_direct_clear(&add->light_direct);
	}
}

void				gui_scene_add_prepare(t_gui_scene_add *add)
{
	CHAR_REF		str;
	GtkTreeIter		iter;
	GtkTreeModel	*model;
	t_object_type	type;

	str = gui_scene_add_gen_name(add);
	gtk_entry_set_text(add->name, "");
	gtk_entry_set_placeholder_text(add->name, str);
	free((void *)str);
	static_default_object(&add->temp_object);
	static_prepare_material(add);
	model = GTK_TREE_MODEL(add->common->types);
	if (!gtk_tree_model_get_iter_first(model, &iter))
		return (rt_raise_error("GUI Creator : Type list is empty"));
	while (1)
	{
		gtk_tree_model_get(model, &iter, gui_list_id, &type, -1);
		if (type == object_type_sphere)
			break ;
		if (!gtk_tree_model_iter_next(model, &iter))
			return ;
	}
	gtk_combo_box_set_active_iter(add->type_combo, &iter);
	static_clear_a(add);
	static_clear_b(add);
}

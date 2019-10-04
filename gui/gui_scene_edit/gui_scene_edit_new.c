/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_edit_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:16:49 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:16:49 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_edit.h"

t_gui_scene_edit		*gui_scene_edit_new(GtkBuilder *builder)
{
	t_gui_scene_edit	*new;

	printf("GUI : Initializing object editor\n");
	new = rt_malloc(sizeof(t_gui_scene_edit));
	new->common = NULL;
	gui_scene_edit_init_own(new, builder);
	gui_scene_edit_init_light_point(new, builder);
	gui_scene_edit_init_light_direct(new, builder);
	gui_scene_edit_init_sphere(new, builder);
	gui_scene_edit_init_plane(new, builder);
	gui_scene_edit_init_cone(new, builder);
	gui_scene_edit_init_cylinder(new, builder);
	gui_scene_edit_init_box(new, builder);
	gui_scene_edit_init_paraboloid(new, builder);
	gui_scene_edit_init_moebius(new, builder);
	gui_scene_edit_init_limited(new, builder);
	gui_scene_edit_init_torus(new, builder);
	gui_scene_edit_init_mandelbulb(new, builder);
	gui_scene_edit_init_julia(new, builder);
	gui_scene_edit_init_p_cube(new, builder);
	gui_scene_edit_init_explosion(new, builder);
	gui_scene_edit_init_csg(new, builder);
	gui_scene_edit_init_material(new, builder);
	new->current_id = -1;
	return (new);
}

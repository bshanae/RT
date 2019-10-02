/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_add_new.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:36:53 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:36:56 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_add.h"

static void			static_init(t_gui_scene_add *add, GtkBuilder *builder)
{
	gui_scene_add_init_own(add, builder);
	gui_scene_add_init_light_point(add, builder);
	gui_scene_add_init_light_direct(add, builder);
	gui_scene_add_init_sphere(add, builder);
	gui_scene_add_init_plane(add, builder);
	gui_scene_add_init_cone(add, builder);
	gui_scene_add_init_cylinder(add, builder);
	gui_scene_add_init_box(add, builder);
	gui_scene_add_init_paraboloid(add, builder);
	gui_scene_add_init_moebius(add, builder);
	gui_scene_add_init_limited(add, builder);
	gui_scene_add_init_torus(add, builder);
	gui_scene_add_init_mandelbulb(add, builder);
	gui_scene_add_init_julia(add, builder);
	gui_scene_add_init_p_cube(add, builder);
	gui_scene_add_init_explosion(add, builder);
	gui_scene_add_init_csg(add, builder);
	gui_scene_add_init_material(add, builder);
}

t_gui_scene_add		*gui_scene_add_new(GtkBuilder *builder)
{
	t_gui_scene_add	*new;

	printf("GUI : Initializing object creator\n");
	new = rt_malloc(sizeof(t_gui_scene_add));
	new->common = NULL;
	new->current_type = object_type_end;
	new->generator_next_id = 0;
	static_init(new, builder);
	return (new);
}

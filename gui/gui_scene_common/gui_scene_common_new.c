/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_common_new.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:43:29 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_common.h"

t_gui_scene_common		*gui_scene_common_new(GtkBuilder *builder)
{
	t_gui_scene_common	*new;

	new = rt_malloc(sizeof(t_gui_scene_common));
	new->connected = rt_false;
	new->ptr_scene = NULL;
	new->ptr_light = NULL;
	new->full = RT_GUI_GET(builder, "scene_list");
	new->limited_main = RT_GUI_GET(builder, "scene_limited_main_list");
	new->limited_limit = RT_GUI_GET(builder, "scene_limited_limit_list");
	new->csg = RT_GUI_GET(builder, "scene_csg_list");
	new->types = RT_GUI_GET(builder, "scene_type_list");
	new->textures = RT_GUI_GET(builder, "scene_texture_list");
	new->background = RT_GUI_GET(builder, "scene_background_list");
	new->reset_generator = rt_false;
	gui_scene_common_update_background_wrapped(new);
	return (new);
}

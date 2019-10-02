/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:15:33 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:15:33 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene.h"

t_gui_scene			*gui_scene_new(GtkBuilder *builder)
{
	t_gui_scene		*new;

	new = rt_malloc(sizeof(t_gui_scene));
	new->common = gui_scene_common_new(builder);
	new->edit = gui_scene_edit_new(builder);
	new->edit->common = new->common;
	new->add = gui_scene_add_new(builder);
	new->add->common = new->common;
	return (new);
}

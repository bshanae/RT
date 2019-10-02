/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:15:22 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:15:22 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene.h"

void				gui_scene_delete(t_gui_scene **scene)
{
	gui_scene_common_delete(&(*scene)->common);
	gui_scene_edit_delete(&(*scene)->edit);
	gui_scene_add_delete(&(*scene)->add);
	free(*scene);
	*scene = NULL;
}

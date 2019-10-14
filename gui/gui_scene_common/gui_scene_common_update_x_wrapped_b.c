/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_common_update_x_wrapped_b.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:10:16 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/14 13:10:17 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_common.h"

void				gui_scene_common_update_textures_wrapped
	(t_gui_scene_common *gui)
{
	gui_scene_common_update_wrap(gui, gui_scene_common_update_textures);
}

void				gui_scene_common_update_background_wrapped
	(t_gui_scene_common *gui)
{
	gui_scene_common_update_wrap(gui, gui_scene_common_update_background);
}

void				gui_scene_common_update_all_wrapped
	(t_gui_scene_common *gui)
{
	gui_scene_common_update_wrap(gui, gui_scene_common_update_all);
}

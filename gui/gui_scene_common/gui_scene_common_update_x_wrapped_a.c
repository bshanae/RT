/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_common_update_x_wrapped_a.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:10:09 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/14 13:10:17 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_common.h"

void				gui_scene_common_update_full_wrapped
	(t_gui_scene_common *gui)
{
	gui_scene_common_update_wrap(gui, gui_scene_common_update_full);
}

void				gui_scene_common_update_limited_wrapped
	(t_gui_scene_common *gui)
{
	gui_scene_common_update_wrap(gui, gui_scene_common_update_limited);
}

void				gui_scene_common_update_csg_wrapped
	(t_gui_scene_common *gui)
{
	gui_scene_common_update_wrap(gui, gui_scene_common_update_csg);
}

void				gui_scene_common_update_types_wrapped
	(t_gui_scene_common *gui)
{
	gui_scene_common_update_wrap(gui, gui_scene_common_update_types);
}

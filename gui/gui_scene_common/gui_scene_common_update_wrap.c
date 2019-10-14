/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_common_update_wrap.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:14:40 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/14 13:14:40 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_common.h"

void				gui_scene_common_update_wrap
	(t_gui_scene_common *gui, t_gui_scene_update_function *func)
{
	gui->update_process = rt_true;
	func(gui);
	gui->update_process = rt_false;
}

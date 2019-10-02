/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:21:05 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:21:05 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void				gui_loop(t_gui *gui)
{
	scene_select(gui->renderer->data.scene, 0);
	gui_scene_edit_select(gui->scene->edit, gui->renderer->data.scene);
	gui_queue_start(gui->queue);
	gtk_main();
}

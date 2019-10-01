/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:20:24 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:20:24 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void				gui_delete(t_gui **gui)
{
	gui_queue_delete(&(*gui)->queue);
	gui_parser_delete(&(*gui)->parser);
	gui_camera_delete(&(*gui)->camera);
	gui_scene_delete(&(*gui)->scene);
	gui_settings_delete(&(*gui)->settings);
	gui_image_delete(&(*gui)->image);
	cl_renderer_delete(&(*gui)->renderer);
	free(*gui);
	*gui = NULL;
}

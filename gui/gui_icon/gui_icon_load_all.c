/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_icon_load_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:36:41 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:36:43 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_icon.h"

void				gui_icon_load_all(GtkBuilder *builder)
{
	t_pair_i		size;

	printf("GUI : Loading icons\n");
	size = (t_pair_i){20, 20};
	gui_icon_load(builder, "icon_parser", RT_SOURCE_GUI_ICON_PARSER, size);
	gui_icon_load(builder, "icon_camera", RT_SOURCE_GUI_ICON_CAMERA, size);
	gui_icon_load(builder, "icon_scene", RT_SOURCE_GUI_ICON_SCENE, size);
	gui_icon_load(builder, "icon_settings", RT_SOURCE_GUI_ICON_SETTINGS, size);
	size = (t_pair_i){14, 14};
	gui_icon_load(builder, "icon_plus", RT_SOURCE_GUI_ICON_PLUS, size);
	gui_icon_load(builder, "icon_minus", RT_SOURCE_GUI_ICON_MINUS, size);
	size = (t_pair_i){16, 16};
	gui_icon_load(builder, "icon_add_no", RT_SOURCE_GUI_ICON_ADD_NO, size);
	gui_icon_load(builder, "icon_add_yes", RT_SOURCE_GUI_ICON_ADD_YES, size);
}

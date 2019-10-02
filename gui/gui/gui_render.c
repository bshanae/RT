/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:25:11 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:25:11 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void				gui_render(t_gui *gui)
{
	cl_renderer_render(gui->renderer);
	gui_settings_show_samples(gui->settings);
}

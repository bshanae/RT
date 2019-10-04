/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_connect_x.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:24:07 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:24:35 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_SIGNAL_CONNECT_X_H
# define GUI_SIGNAL_CONNECT_X_H

# include "gui_signal_connect_macro.h"

# include "gui.h"
# include "gui_signal_x.h"

void				gui_signal_connect_all(t_gui *gui);

void				gui_signal_connect_entry(t_gui *gui);
void				gui_signal_connect_parser(t_gui *gui);
void				gui_signal_connect_camera(t_gui *gui);
void				gui_signal_connect_scene_edit(t_gui *gui);
void				gui_signal_connect_scene_add(t_gui *gui);
void				gui_signal_connect_settings(t_gui *gui);
void				gui_signal_connect_image(t_gui *gui);

#endif

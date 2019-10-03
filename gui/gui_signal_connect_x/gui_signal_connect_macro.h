/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_signal_connect_macro.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 13:23:12 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/03 13:23:12 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_SIGNAL_CONNECT_MACRO_H
# define GUI_SIGNAL_CONNECT_MACRO_H

# define GTK_ADD_CALLBACK		gtk_builder_add_callback_symbol
# define RT_GUI_CONNECT(g, s)	GTK_ADD_CALLBACK(g->builder, #s, G_CALLBACK(s))

#endif

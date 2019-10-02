/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_material_color_x.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:40:56 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:40:58 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_material.h"

void				gui_material_color_enable(t_gui_material *material)
{
	gtk_widget_set_sensitive(material->color_box, 1);
}

void				gui_material_color_disable(t_gui_material *material)
{
	gtk_widget_set_sensitive(material->color_box, 0);
}

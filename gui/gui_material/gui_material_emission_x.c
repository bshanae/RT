/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_material_emission_x.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:20:31 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/14 13:20:31 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_material.h"

void			gui_material_emission_enable(t_gui_material *material)
{
	gtk_widget_set_sensitive(material->emission_box, 1);
}

void			gui_material_emission_disable(t_gui_material *material)
{
	gtk_widget_set_sensitive(material->emission_box, 0);
}

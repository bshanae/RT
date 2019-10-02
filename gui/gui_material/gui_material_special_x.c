/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_material_special_x.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:48:49 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:48:51 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_material.h"

void				gui_material_special_disable(t_gui_material *material)
{
	gtk_widget_set_sensitive(GTK_WIDGET(material->reflectance_label), FALSE);
	gtk_widget_set_sensitive(GTK_WIDGET(material->transparency_label), FALSE);
	gtk_widget_set_sensitive(GTK_WIDGET(material->reflectance_scale), FALSE);
	gtk_widget_set_sensitive(GTK_WIDGET(material->transparency_scale), FALSE);
}

void				gui_material_special_enable(t_gui_material *material)
{
	gtk_widget_set_sensitive(GTK_WIDGET(material->reflectance_label), TRUE);
	gtk_widget_set_sensitive(GTK_WIDGET(material->transparency_label), TRUE);
	gtk_widget_set_sensitive(GTK_WIDGET(material->reflectance_scale), TRUE);
	gtk_widget_set_sensitive(GTK_WIDGET(material->transparency_scale), TRUE);
}

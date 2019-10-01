/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_material_hide.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:42:29 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:42:31 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_material.h"

void				gui_material_hide(t_gui_material *material)
{
	gtk_stack_set_visible_child_name(material->switcher_stack, "hide");
	gtk_stack_set_visible_child_name(material->stack, "hide");
}

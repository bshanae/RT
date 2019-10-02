/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_scene_add_delete.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 16:25:24 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 16:25:28 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_scene_add.h"

void				gui_scene_add_delete(t_gui_scene_add **object)
{
	free(*object);
	*object = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_camera_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:27:52 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:27:52 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_camera.h"

void				gui_camera_delete(t_gui_camera **camera)
{
	free(*camera);
	*camera = NULL;
}

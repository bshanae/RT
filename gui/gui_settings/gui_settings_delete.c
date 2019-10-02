/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_settings_delete.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:01:14 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 17:01:16 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_settings.h"

void				gui_settings_delete(t_gui_settings **settings)
{
	free(*settings);
	*settings = NULL;
}

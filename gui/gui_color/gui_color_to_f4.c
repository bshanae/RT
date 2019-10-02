/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_color_to_f4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:33:20 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:33:20 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_color.h"

RT_F4_API			gui_color_to_f4(const t_gui_color *source)
{
	RT_F4_API		result;

	result.x = source->red;
	result.y = source->green;
	result.z = source->blue;
	result.w = source->alpha;
	return (result);
}

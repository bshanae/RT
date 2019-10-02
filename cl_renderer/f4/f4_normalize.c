/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f4_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:28:58 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "f4.h"

RT_F4_API			f4_normalize(RT_F4_API source)
{
	RT_F			length;

	length = f4_length(source);
	return ((RT_F4_API){
		source.x / length,
		source.y / length,
		source.z / length,
		source.w
		});
}

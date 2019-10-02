/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_iter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:24:25 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

RT_F4_API			*texture_iter(t_texture *texture)
{
	RT_F4_API		*pointer;
	int				i;

	i = 0;
	pointer = &texture->data[0];
	while (i < texture->textures_number)
		pointer += texture->texture_length[i++];
	return (pointer);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_convert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:23:52 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

void				texture_convert(
					const t_texture *texture,
					RT_F4_API *pointer,
					const unsigned char *stbi_data)
{
	int				pixel_index;
	int				size;

	pixel_index = 0;
	size = texture->texture_length[texture->textures_number] * TEXTURE_CHANNELS;
	while (pixel_index < size)
	{
		pointer->x = (RT_F)stbi_data[pixel_index] / 255;
		pointer->y = (RT_F)stbi_data[pixel_index + 1] / 255;
		pointer->z = (RT_F)stbi_data[pixel_index + 2] / 255;
		pointer->w = 1.;
		pointer++;
		pixel_index += TEXTURE_CHANNELS;
	}
}

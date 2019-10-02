/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_data_load.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:23:57 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define STB_IMAGE_IMPLEMENTATION

#include "texture.h"

void				texture_data_load(
					t_texture *texture, const char *path, CHAR_REF name)
{
	unsigned char	*stbi_data;
	int				number_of_channels;

	stbi_set_flip_vertically_on_load(0);
	texture->textures_number++;
	if (!stbi_info(path, &texture->width[texture->textures_number],
		&texture->height[texture->textures_number], &number_of_channels))
		rt_raise_error("Texture : Invalid file");
	stbi_data = stbi_load(path, &texture->width[texture->textures_number],
		&texture->height[texture->textures_number],
		&number_of_channels, TEXTURE_CHANNELS);
	ft_strcpy(texture->name[texture->textures_number], name);
	texture->height[texture->textures_number]--;
	texture->texture_length[texture->textures_number] =
		texture->width[texture->textures_number]
		* texture->height[texture->textures_number];
	texture_fill_data(texture, stbi_data);
}

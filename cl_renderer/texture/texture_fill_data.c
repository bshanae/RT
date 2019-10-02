/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_fill_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:24:08 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

void				texture_fill_data(
					t_texture *texture,
					unsigned char *stbi_data)
{
	RT_F4_API		*pointer;

	pointer = texture_iter(texture);
	texture_convert(texture, pointer, stbi_data);
	stbi_image_free(stbi_data);
}

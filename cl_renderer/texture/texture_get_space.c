#include "texture.h"

void				texture_get_space(t_texture *texture)
{
	if (!texture->textures_number)
		texture->data = (RT_F4_API *)malloc(sizeof(RT_F4_API)* texture->texture_length[texture->textures_number]);
	else
		texture->data = ft_realloc(
				(void*)&texture->data,
				sizeof(RT_F4_API) * (texture->data_size - texture->texture_length[texture->textures_number]),
				sizeof(RT_F4_API) * (texture->data_size));
}

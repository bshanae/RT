#include "texture.h"

void				texture_get_space(t_texture *texture)
{
	texture->data = ft_realloc(
				(void*)&texture->data,
				sizeof(texture->data),
				sizeof(texture->data)
				+ texture->texture_length[texture->textures_number] * sizeof(RT_F4_API));
}

#include "texture.h"

void				texture_fill_data(
					t_texture *texture,
					unsigned char *stbi_data)
{
	int 			i;
	RT_F4_API		*pointer;

	i = 0;
	texture_get_space(texture);
	pointer = &texture->data[0];
	while (i < texture->textures_number)
		pointer += texture->texture_length[i++];
	texture_convert(texture, pointer, stbi_data);
	for (int j = 0; j < texture->texture_length[texture->textures_number] - 1; j++)
		printf("%f %f %f\n", texture->data[j].x, texture->data[j].y, texture->data[j].z);
	stbi_image_free(stbi_data);
}

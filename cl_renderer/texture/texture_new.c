#include "texture.h"

t_texture			*texture_new(void)
{
	t_texture		*new;

	new = (t_texture *)malloc(sizeof(t_texture));
	ft_bzero(new, sizeof(t_texture));
	new->textures_number = -1;
	ft_bzero(new->data, sizeof(RT_F4_API) * TEXTURE_DATA_SIZE);
	texture_data_load(new, TEXTURE_CHESS);
	printf("%f\n", new->data[5000].x);
	return (new);
}

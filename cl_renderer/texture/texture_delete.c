#include "texture.h"

void 				texture_delete(t_texture **texture)
{
	free(*texture);
	*texture = NULL;
}

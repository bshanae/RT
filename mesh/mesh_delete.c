#include "mesh.h"

void				mesh_delete(t_mesh **mesh)
{
	if (!*mesh)
		return ;
	free((*mesh)->triangles);
	free(*mesh);
	*mesh = NULL;
}
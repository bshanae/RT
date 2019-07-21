#include "mesh.h"

void				mesh_delete(t_mesh **mesh)
{
	free((*mesh)->triangles);
	free(*mesh);
	*mesh = NULL;
}
#include "mesh.h"

int							mesh_intersect(t_mesh *mesh, t_intersection *intersection)
{
	int 					result;

	result = -1;
	for (int i = 0; i < mesh->triangles_number; i++)
		if (triangle_intersect(mesh->triangles + i, intersection))
			result = i;
	if (result != -1)
		intersection->material = mesh->material;
	return (result != -1);
}
#include "mesh.h"

int							mesh_intersect(t_mesh *mesh, t_intersection *intersection)
{
	int 					result;

	result = -1;
	for (int i = 0; i < mesh->triangles_number; i++)
		if (shape_intersect_triangle(mesh->triangles + i, intersection))
			result = i;
	return (result != -1);
}
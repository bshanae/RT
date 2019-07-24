#include "accelerated_mesh.h"

#include <stdio.h>

int 				accelerated_mesh_intersect(t_accelerated_mesh *mesh ,t_intersection *intersection)
{
	if (kd_tree_intersect(mesh->kd_tree, intersection))
	{
		intersection->material = mesh->mesh->material;
		intersection->hit = ray_calculate(&intersection->ray);
		intersection->shape_index = 1000;
		return (1);
	}
	return (0);
}
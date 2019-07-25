#include "accelerated_mesh.h"

#include <stdio.h>

int 				double_intersection;

int 				accelerated_mesh_intersect(t_accelerated_mesh *mesh, t_intersection *intersection)
{
	double_intersection = 0;
	if (kd_tree_intersect(mesh->kd_tree, intersection))
	{
		intersection->material = mesh->mesh->material;
		intersection->hit = ray_calculate(&intersection->ray);
		return (1);
	}
	return (0);
}
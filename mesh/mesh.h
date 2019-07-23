#ifndef MESH_H
# define MESH_H

# include "libft_standart.h"

# include "triangle.h"

typedef struct			s_mesh
{
	t_triangle			*triangles;
	int 				triangles_number;
	t_material			material;
}						t_mesh;

t_mesh					*mesh_new(const char *file_name, t_material material);

void					mesh_delete(t_mesh **mesh);

int						mesh_intersect(t_mesh *mesh, t_intersection *intersection);

#endif

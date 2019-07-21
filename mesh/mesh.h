#ifndef MESH_H
# define MESH_H

# include "shape_list.h"

# include "objpar.h"
# include "open_file.h"

typedef struct		s_mesh_temp
{
	objpar_data_t	obj;
	void			*buffer[2];
}					t_mesh_temp;

typedef struct		s_mesh
{
	t_shape			*triangles;
	int 			triangles_number;
}					t_mesh;

t_mesh				*mesh_new(const char *file_name, t_material material);

void				mesh_delete(t_mesh **mesh);

int					mesh_intersect(t_mesh *mesh, t_intersection *intersection);

#endif

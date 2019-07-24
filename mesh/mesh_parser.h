#ifndef MESH_PARSER_H
# define MESH_PARSER_H

# define TINYOBJ_LOADER_C_IMPLEMENTATION
# include "tinyobj_loader_c.h"

typedef struct			s_mesh_temp
{
	char 				*file_buffer;
	int 				file_length;
	tinyobj_attrib_t	attributes;
	tinyobj_shape_t		*shapes;
	size_t 				shapes_length;
	tinyobj_material_t* materials;
	size_t				materials_length;
}						t_mesh_temp;

#endif

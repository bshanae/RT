#ifndef KD_TREE_H
# define KD_TREE_H

# include "mesh.h"

typedef struct 		s_kd_tree_array
{
	int 			*polygons;
	int 			length;
}					t_kd_tree_array;

t_kd_tree_array		kd_tree_array_create(int length)

typedef struct		s_kd_tree_bb
{
	t_vector3		min;
	t_vector3		max;
	t_vector3		middle;
}					t_kd_tree_bb;

t_kd_tree_bb		kd_tree_bb_create(t_kd_tree_array *array);

typedef struct 		s_kd_tree_node t_kd_tree_node;

struct 				s_kd_tree_node
{
	t_kd_tree_node	*left;
	t_kd_tree_node	*right;
	t_kd_tree_array	array;
	int 			depth;
};

t_kd_tree_node		*kd_tree_node_create(void);

t_kd_tree_node		*kd_tree_build(t_mesh *mesh);

#endif

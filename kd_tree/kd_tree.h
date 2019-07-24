#ifndef KD_TREE_H
# define KD_TREE_H

# include "mesh.h"

typedef enum 		e_kd_tree_axis
{
	axis_x,
	axis_y,
	axis_z
}					t_kd_tree_axis;

typedef struct 		s_kd_tree_array
{
	int 			*indexes;
	int 			length;
	int 			capacity;
}					t_kd_tree_array;

t_kd_tree_array		kd_tree_array_create(int capacity);

void				kd_tree_array_add(t_kd_tree_array *array, INT_REF value);
float 				kd_tree_array_find_median(const t_kd_tree_array *array, const t_mesh *mesh, t_kd_tree_axis axis);

typedef struct		s_kd_tree_bb
{
	t_vector3		min;
	t_vector3		max;
	t_vector3		middle;
}					t_kd_tree_bb;

typedef enum 		e_kd_tree_side
{
	side_left,
	side_right
}					t_kd_tree_side;

t_kd_tree_bb		kd_tree_bb_create(const t_mesh *mesh, t_kd_tree_array *array);

t_kd_tree_axis		kd_tree_bb_find_cut_axis(const t_kd_tree_bb *bb);
t_kd_tree_side		kd_tree_bb_find_triangle_side(const t_triangle *triangle, t_kd_tree_axis axis, const float *median);
int 				kd_tree_bb_intersect(t_kd_tree_bb *bb, t_intersection *intersection);


typedef struct 		s_kd_tree_node t_kd_tree_node;

struct 				s_kd_tree_node
{
	t_kd_tree_node	*left;
	t_kd_tree_node	*right;
	t_kd_tree_array	array;
	t_kd_tree_bb	bb;
	const t_mesh	*mesh;
};

t_kd_tree_node		*kd_tree_node_create(const t_mesh *mesh);
t_kd_tree_node		*kd_tree_build(const t_mesh *mesh);
void				kd_tree_destroy(t_kd_tree_node **node);
int 				kd_tree_intersect(t_kd_tree_node *node, t_intersection *intersection);


#endif

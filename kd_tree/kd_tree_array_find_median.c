#include "kd_tree.h"

#include <stdio.h>

typedef struct		s_pair_fi
{
	float 			f;
	int 			i;
}					t_pair_fi;

static void			sort(t_pair_fi *array, int length)
{
	for (int i = 1; i < length; length--)
		for (int j = i; j < length; j++)
			if (array[j - 1].f > array[j].f)
				swap_memory(array + j - 1, array + j, sizeof(t_pair_fi));
}

float 				kd_tree_array_find_median(const t_kd_tree_array *array, const t_mesh *mesh, t_kd_tree_axis axis)
{
	t_pair_fi		*temp;
	float 			median;

	temp = (t_pair_fi *)malloc(sizeof(t_pair_fi) * array->length);
	for (int i = 0; i < array->length; i++)
	{
		temp[i].i = i;
		temp[i].f = (*vector3_iter(&mesh->triangles[array->indexes[i]].min, axis) + *vector3_iter(&mesh->triangles[array->indexes[i]].max, axis)) / 2.;
	}
	sort(temp, array->length);
	if (array->length % 2)
		median =  (temp[(array->length + 1) / 2 - 1].f + temp[(array->length + 1) / 2].f) / 2.;
	else
		median =  (temp[array->length / 2 - 1].f + temp[array->length / 2].f) / 2.;
//	for (int i = 0; i < array->length; i++)
//		printf("[%i, %f] ", temp[i].i, temp[i].f);
//	printf(" : median = %f\n", median);
	free(temp);
	return (median + 0.000001f);
}
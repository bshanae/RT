#include "material.h"

t_material			*material_new(t_vector3 color, float diffuse, float specular, float reflect, float refract)
{
	t_material		*new;

	if (!(new = (t_material *)malloc(sizeof(t_material))))
		exit(21);
	new->color = color;
	new->diffuse = diffuse;
	new->specular = specular;
	new->reflect = reflect;
	new->refract = refract;
	return (new);
}
#include "object_interaction.h"

int 				object_intersect
					(t_object *object, t_intersection *intersection)
{
	if (object->type == object_sphere)
		return (object_sphere_intersect(object, intersection));
	if (object->type == object_plane)
		return (object_plane_intersect(object, intersection));
	ft_assert(1 == 0, "unknown object type");
	return (0);
}
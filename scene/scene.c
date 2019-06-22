#include "scene.h"

t_scene             *scene_new(t_vector3 background)
{
	t_scene			*new;

	if (!(new = (t_scene *)malloc(sizeof(t_scene))))
		exit(21);
	new->shapes = vector_create(sizeof(t_shape *));
	new->lights = vector_create(sizeof(t_light *));
	new->background = background;
	new->settings.diffuse_light = 1;
	new->settings.specular_light = 1;
	new->settings.shadows = 1;
	new->settings.tshadows = 1;
	return (new);
}

void				scene_delete(t_scene **me)
{
	int 			i;
	t_shape			*shape;
	t_light         *light;


	i = 0;
	while (i < (*me)->shapes.length)
	{
		shape = scene_shape_at(*me, i++);
		shape_delete(&shape);
	}
	vector_destroy(&(*me)->shapes);
	i = 0;
	while (i < (*me)->lights.length)
	{
		light = scene_light_at(*me, i++);
		light_delete(&light);
	}
	vector_destroy(&(*me)->lights);
	free(*me);
	*me = NULL;
}

int 				scene_intersect(t_scene *me, t_intersection *intersection)
{
	int 			i;
	t_shape			*shape;
	int 			result;

	i = 0;
	result = 0;
	while (i < me->shapes.length)
	{
		shape = scene_shape_at(me, i++);
		result += shape->intersect(shape, intersection);
	}
	return (result != 0);
}

int                 scene_check_shadow(t_scene *me, t_intersection *intersection, t_vector3 *light_direction)
{
	t_intersection	shadow;

	intersection_reset(&shadow);
	shadow.ray.origin = ray_intersect(&intersection->ray);
	shadow.ray.direction = *light_direction;
	scene_intersect(me, &shadow);
	if (shadow.ray.t >= RAY_T_MIN && shadow.ray.t <= vector3_length(light_direction))
	{
		if (me->settings.tshadows && shadow.material->refract)
		{
			intersection->shadow_ratio = shadow.material->refract;
			return (0);
		}
		return (1);
	}
	return (0);
}

void				scene_light_up(t_scene *me, t_intersection *intersection)
{
	int             i;
	t_light         *light;
	t_vector3       light_direction;

	i = 0;
	while(i < me->lights.length)
	{
		light = scene_light_at(me, i++);
		intersection->shadow_ratio = 1.;
		if (light->type == light_ambient)
		{
			intersection->diffuse_intensity += light->intensity;
			continue ;
		}
		else
			light_direction = intersection_light_direction(intersection, light);
		if (me->settings.shadows && scene_check_shadow(me, intersection, &light_direction))
			continue ;
		if (me->settings.diffuse_light)
			intersection_lighting_diffuse(intersection, light, &light_direction);
		if (me->settings.specular_light)
			intersection_lighting_specular(intersection, light, &light_direction);
	}
	intersection_make_color(intersection);
}

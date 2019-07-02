#include "scene.h"

t_scene				*scene_new(void)
{
	t_scene			*new;

	if (!(new = (t_scene *)malloc(sizeof(t_scene))))
		exit(21);
	new->background = SCENE_DEF_BACKGROUND;
	new->lights_length = 0;
	new->shapes_length = 0;
	return (new);
}

void				scene_delete(t_scene **scene)
{
	free(*scene);
	*scene = NULL;
}

void				scene_add_light(t_scene *scene, t_light light)
{
	if (scene->lights_length < SCENE_LIGHT_CAPACITY)
		scene->lights[scene->lights_length++] = light;
}

void				scene_add_shape(t_scene *scene, t_shape shape)
{
	if (scene->shapes_length < SCENE_SHAPE_CAPACITY)
		scene->shapes[scene->shapes_length++] = shape;
}

int 				scene_intersect(t_scene *scene, t_intersection *intersection)
{
	u_long			i;
	int 			result;

	i = 0;
	result = 0;
	while (i < scene->shapes_length)
		result += shape_intersect(scene->shapes + i++, intersection);
	return (result != 0);
}

void				scene_light_up(t_scene *scene, t_intersection *intersection)
{
	u_long			i;
	t_light			*light;
	t_vector3		light_direction;

	i = 0;
	while(i < scene->lights_length)
	{
		intersection->shadow_ratio = 1.;
		light = scene->lights + i++;
		light_direction = intersection_light_direction(intersection, light);
		intersection_lighting_diffuse(intersection, light, &light_direction);
		//intersection_lighting_specular(intersection, light, &light_direction);
	}
	intersection_make_color(intersection);
}
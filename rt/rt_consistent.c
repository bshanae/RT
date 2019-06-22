#include "rt.h"

t_vector3			rt_ray_trace(t_rt *me, t_intersection *original, int reflection_depth, int refraction_depth)
{
	t_intersection	reflection;
	t_intersection	refraction;

	if (reflection_depth < 0 && refraction_depth < 0)
		return (me->scene->background);
	intersection_reset(original);
	if (!scene_intersect(me->scene, original))
		return (me->scene->background);
	if (*original->highlight)
		return ((t_vector3){1., 1., 1.});
	scene_light_up(me->scene, original);
	//reflection
	if (original->material->reflect && reflection_depth > 0)
	{
		intersection_reflect(&reflection, original);
		reflection.color = rt_ray_trace(me, &reflection, --reflection_depth, refraction_depth);
		vector3_mul_eq(&reflection.color, original->material->reflect);
		original->color = vector3_add(&original->color, &reflection.color);
	}
	// refraction
	if (original->material->refract && refraction_depth > 0)
	{
		intersection_refract(&refraction, original);
		refraction.color = rt_ray_trace(me, &refraction, reflection_depth, --refraction_depth);
		vector3_mul_eq(&refraction.color, original->material->refract);
		original->color = vector3_add(&original->color, &refraction.color);
	}
	return (original->color);
}

void				rt_consistent(t_rt *me)
{
	int 			x;
	int 			y;
	t_vector3		vp;
	t_intersection	intersection;

	x = 0;
	vp.z = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			vp.x = x - (WIN_WIDTH - 1) / 2.;
			vp.y = -y + (WIN_HEIGHT - 1) / 2.;
			intersection.ray = camera_cast_ray(me->camera, &vp);
			me->img_data[x + y * WIN_WIDTH] = color_unpack(rt_ray_trace(me, &intersection, me->settings.reflection_depth, me->settings.refraction_depth));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(me->mlx_ptr, me->win_ptr, me->img_ptr, 0, 0);
}
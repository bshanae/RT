#include "rt.h"



void 					rt_parallel(t_rt *me)
{
	u_long				i;
	t_shape				*shape_iter;
	t_light				*light_iter;

	// CAMERA

	camera_build_cl(me->camera, &me->open_cl->host.camera);

	// DEPTH

	me->open_cl->host.reflection_depth = me->settings.reflection_depth;
	me->open_cl->host.refraction_depth = me->settings.refraction_depth;

	// SCENE

	me->open_cl->host.scene.settings = me->scene->settings;
	me->open_cl->host.scene.background = me->scene->background;
	me->open_cl->host.scene.shape_data_element_size = SHAPE_SIZE_MAX;
	me->open_cl->host.scene.shape_number = me->scene->shapes.length;
	me->open_cl->host.scene.light_number = me->scene->lights.length;
	me->open_cl->host.scene.shape_type_number = SHAPE_TYPE_NUM;

	// SHAPE_DATA

	i = 0;
	while (i < me->scene->shapes.length)
	{
		shape_iter = scene_shape_at(me->scene, i);
		ft_memcpy(me->open_cl->host.shape_data + i * SHAPE_SIZE_MAX, shape_iter->data, shape_iter->data_size);
		//t_sphere_data *d = me->open_cl->host.shape_data + i * SHAPE_SIZE_MAX;
		i++;
	}

	// SHAPES

	i = 0;
	while (i < me->scene->shapes.length)
	{
		shape_iter = scene_shape_at(me->scene, i);
		*(t_material *)(&me->open_cl->host.shapes[i].material) = *shape_iter->material;
		me->open_cl->host.shapes[i].highlight = shape_iter->highlight;
		me->open_cl->host.shapes[i].function_index = shape_find_function_ptr(shape_iter->intersect);
		i++;
	}

	// LIGHTS

	i = 0;
	while (i < me->scene->lights.length)
	{
		light_iter = scene_light_at(me->scene, i);
		me->open_cl->host.lights[i] = *light_iter;
		i++;
	}

	// RUNS KERNELS

	open_cl_run(me->open_cl);

	mlx_put_image_to_window(me->mlx_ptr, me->win_ptr, me->img_ptr, 0, 0);
}
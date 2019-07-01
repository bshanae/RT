/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:12:32 by ashari            #+#    #+#             */
/*   Updated: 2019/07/01 12:05:47 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "mlx.h"
# include "intersection.h"
# include "scene.h"
# include "shape_list.h"
# include "open_cl.h"
# include "mlx_keys.h"

# define RT_CAMERA_POS_STEP		0.15
# define RT_CAMERA_DIR_STEP		0.01

# define RT_SCENE_CAPACITY		8

typedef struct					s_control_light
{
	int							is_on;
	int							index;
}								t_control_light;

typedef struct					s_control_shape
{
	int							is_on;
	int							index;
}								t_control_shape;

typedef struct					s_scenes
{
	t_scene						*data[RT_SCENE_CAPACITY];
	int							length;
	int							index;
	t_scene						**current;
}								t_scenes;

typedef	struct s_rt				t_rt;

struct							s_rt
{
	void						*mlx_ptr;
	void						*win_ptr;
	void						*img_ptr;
	int							*img_data;
	t_scenes					scenes;
	t_control_light				ctrl_light;
	t_control_shape				ctrl_shape;
	t_rt						*clone;
	t_open_cl					*open_cl;
};

t_rt							*rt_new();

void							rt_delete(t_rt **me);

void							rt_clone(t_rt *me);

void							rt_reset(t_rt **rt);

void							rt_add_scene(t_rt *me, t_scene *scene);

void							rt_render(t_rt *me);

int								rt_ctrl_camera_move(t_rt *rt, int key);

int								rt_ctrl_camera_rotate(t_rt *rt, int key);

int								rt_ctrl_scene(t_rt *rt, int key);

int								rt_key_press(int key, void *ptr);

int								rt_key_release(int key, void *ptr);

int								rt_exit(void *ptr);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:12:51 by ashari            #+#    #+#             */
/*   Updated: 2019/07/02 11:17:32 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "parameters.h"

# include "shape.h"
# include "shape_list.h"
# include "light.h"
# include "libft_vector.h"
# include "camera.h"

# define SCENE_DEF_BACKGROUND 	(t_vector3){.7, .7, .7}

typedef	struct					s_scene
{
	t_camera					camera;
	t_shape						shapes[SCENE_SHAPE_CAPACITY];
	int							shapes_length;
	t_light						lights[SCENE_LIGHT_CAPACITY];
	int							lights_length;
	t_vector3					background;
}								t_scene;

t_scene							*scene_new();

void							scene_delete(t_scene **me);

void							scene_add_shape(t_scene *me, t_shape shape);

void							scene_add_light(t_scene *me, t_light light);

#endif

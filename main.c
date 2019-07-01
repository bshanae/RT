/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:13:43 by ashari            #+#    #+#             */
/*   Updated: 2019/07/01 12:05:47 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "scene_list.h"

int					main(void)
{
	t_rt			*rt;

	rt = rt_new();
	rt_add_scene(rt, scene_a());
	rt_render(rt);
	mlx_hook(rt->win_ptr, 2, 1, rt_key_press, &rt);
	mlx_hook(rt->win_ptr, 3, 1, rt_key_release, &rt);
	mlx_hook(rt->win_ptr, 17, 1, rt_exit, &rt);
	mlx_loop(rt->mlx_ptr);
}

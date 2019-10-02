/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_renderer_flag_x.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 14:02:43 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CL_RENDERER_FLAG_X_H
# define CL_RENDERER_FLAG_X_H

typedef struct				s_cl_renderer_flag_list
{
	int						update_camera;
	int						update_scene;
	int						update_settings;
	int						reset_samples;
}							t_cl_renderer_flag_list;

typedef enum				e_cl_renderer_flag
{
	cl_flag_update_camera,
	cl_flag_update_scene,
	cl_flag_update_settings,
	cl_flag_reset_samples
}							t_cl_renderer_flag;

#endif

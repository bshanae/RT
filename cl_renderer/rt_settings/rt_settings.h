/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_settings.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:21:23 by ashari            #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_SETTINGS_H
# define RT_SETTINGS_H

# include "rt_cl_include.h"
# include "rt_float.h"
# include "rt_parameters.h"

# include "libft_standart.h"

# include "object_flag.h"

typedef struct			s_cl_renderer_settings
{
	t_rt_light_mod		light_mod;
	RT_F4_API			light_ambient;
	t_rt_bool			illumination;
	RT_F				illumination_value;
	int					sample_count;
	int					sample_limit;
	int					sample_depth;
	int					motion_blur;
	int					motion_blur_sample_count;
	t_rt_tracing_mod	tracing_mod;
	UINT				tracing_mod_mask;
	int					rm_step_limit;
	RT_F				rm_step_part;
	RT_F				rm_max_distance;
}						t_rt_settings;

void					cl_renderer_settings_init(t_rt_settings *settings);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 15:59:02 by ashari            #+#    #+#             */
/*   Updated: 2019/10/17 14:49:25 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_LIST_H
# define COLOR_LIST_H

# include "rt_cl_include.h"
# include "rt_float.h"

# define COLOR_WHITE			(RT_F4_API){1., 1., 1., 1.}
# define COLOR_BLACK			(RT_F4_API){0., 0., 0., 1.}
# define COLOR_RED				(RT_F4_API){1., 0., 0., 1.}
# define COLOR_GREEN			(RT_F4_API){0., 1., 0., 1.}
# define COLOR_BLUE				(RT_F4_API){0., 0., 1., 1.}

# define COLOR_NONE				(RT_F4_API){-1., -1., -1., -1.}

# define LIGHT					(RT_F4_API){1., 1., 1., 1.}
# define LIGHT_SOFT				(RT_F4_API){1., 1., .8, 1.}
# define LIGHT_BASIC			(RT_F4_API){0.5, 0.5, 0.5, 1.}
# define LIGHT_AMBIENT			(RT_F4_API){0.5, 0.5, 0.5, 1.}

# define COLOR_DEEP_BLUE		(RT_F4_API){0.24, 0.29, 0.33, 1.}
# define COLOR_LIGHT_BLUE		(RT_F4_API){1., 0.92, 0.94, 1.}
# define COLOR_GREY				(RT_F4_API){0.77, 0.78, 0.79, 1.}
# define COLOR_NEW_BLUE			(RT_F4_API){0.66, 0.78, 0.89, 1.}

# define COLOR_PINK		        (RT_F4_API){0.83, 0.63, 0.6, 1.}
# define COLOR_YELLOW			(RT_F4_API){0.95, 0.74, 0.55, 1.}

#endif

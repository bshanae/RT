/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:54:22 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_LIST_H
# define MATERIAL_LIST_H

# include "color_list.h"

# define RT_M1					(t_material)

# define MATERIAL_LIGHT			RT_M1{COLOR_BLACK, LIGHT}
# define MATERIAL_LIGHT_BASIC	RT_M1{COLOR_BLACK, LIGHT_BASIC}
# define MATERIAL_LIGHT_AMBIENT	RT_M1{COLOR_BLACK, LIGHT_AMBIENT}

# define MATERIAL_WHITE			RT_M1{COLOR_WHITE, COLOR_BLACK, .0, 0., 0.}
# define MATERIAL_BLACK			RT_M1{COLOR_BLACK, COLOR_BLACK, .0, 0., 0.}
# define MATERIAL_RED			RT_M1{COLOR_RED, COLOR_BLACK, .0, 0., 0.}
# define MATERIAL_GREEN			RT_M1{COLOR_GREEN, COLOR_BLACK, .0, 0., 0.}
# define MATERIAL_BLUE			RT_M1{COLOR_BLUE, COLOR_BLACK, .0, 0., 0.}

# define MATERIAL_MIRROR		RT_M1{COLOR_BLACK, COLOR_BLACK, .0, 1., 0.}
# define MATERIAL_GLASS			RT_M1{COLOR_BLACK, COLOR_BLACK, .0, 0., 1.}

# define MATERIAL_NONE			RT_M1{COLOR_NONE, COLOR_NONE, .0, 0., 0.}

// Mountains palette

# define MATERIAL_DEEP_BLUE 	RT_M1{COLOR_DEEP_BLUE, COLOR_BLACK, .0, 0., 0.}
# define MATERIAL_LIGHT_BLUE 	RT_M1{COLOR_LIGHT_BLUE, COLOR_BLACK, .0, 0., 0.}
# define MATERIAL_GREY          RT_M1{COLOR_GREY, COLOR_BLACK, .0, 0., 0.}
# define MATERIAL_NEW_BLUE      RT_M1{COLOR_NEW_BLUE, COLOR_BLACK, .0, 0., 0.}
# define MATERIAL_DEEP_BLUE 	RT_M1{COLOR_DEEP_BLUE, COLOR_BLACK, .0, 0., 0.}

#endif

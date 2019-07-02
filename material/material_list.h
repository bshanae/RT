/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:11:03 by ashari            #+#    #+#             */
/*   Updated: 2019/07/02 20:11:24 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_LIST_H
# define MATERIAL_LIST_H

# include "color_list.h"

# define MATERIAL_MIRROR		(t_material){COLOR_WHITE, .1, 3.1, .8}
# define MATERIAL_RED			(t_material){COLOR_RED, 1., .3, .0}
# define MATERIAL_GREEN			(t_material){COLOR_GREEN, 1., .3, .0}
# define MATERIAL_BLUE			(t_material){COLOR_BLUE, 1., .3, .0}
# define MATERIAL_GREY			(t_material){COLOR_GREY, 1., .3, .0}
# define MATERIAL_WHITE			(t_material){COLOR_WHITE, 1., .3, .0}
# define MATERIAL_PURPLE		(t_material){COLOR_PURPLE, 1., .3, .0}

# define MATERIAL_ORANGE_SODA	(t_material){COLOR_ORANGE_SODA, 1., .3, .0}
# define MATERIAL_CRAYOLA		(t_material){COLOR_CRAYOLA, 1., .3, .0}
# define MATERIAL_FLAME			(t_material){COLOR_FLAME, 1., .3, .0}
# define MATERIAL_PLATINUM		(t_material){COLOR_PLATINUM, .1, 7.1, 1.}

#endif

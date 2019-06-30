/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:11:03 by ashari            #+#    #+#             */
/*   Updated: 2019/06/30 19:11:04 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_LIST_H
# define MATERIAL_LIST_H

# include "color_list.h"

# define MATERIAL_MIRROR	(t_material){COLOR_WHITE, .1, 4.1, .8}
# define MATERIAL_RED		(t_material){COLOR_RED, 1., .3, .0}

#endif

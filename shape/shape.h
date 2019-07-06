/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:13:27 by ashari            #+#    #+#             */
/*   Updated: 2019/07/06 15:05:40 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "parameters.h"

# include "material.h"
# include "intersection.h"

typedef	struct			s_shape
{
	int					id;
	unsigned char		data[SHAPE_DATA_SIZE_RESERVE];
	t_material			material;
}						t_shape;

int						shape_intersect(t_shape *shape, t_intersection *intersection);

#endif

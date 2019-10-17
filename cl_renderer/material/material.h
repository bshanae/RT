/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:54:16 by ashari            #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "rt_cl_include.h"
# include "rt_float.h"
# include "rt_parameters.h"

typedef struct		s_material
{
	RT_F4_API		color;
	RT_F4_API		emission;
	RT_F			specular;
	RT_F			reflectance;
	RT_F			transparency;
	RT_F			transparency_index;
}					t_material;

#endif

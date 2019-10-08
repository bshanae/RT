/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_material.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:26:39 by sbosmer           #+#    #+#             */
/*   Updated: 2019/10/08 19:28:44 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "jsmn.h"
#include "json_parse.h"

t_material	decide_color(char *mat_name)
{
	t_material		res;
	t_color2		col;

	res = MATERIAL_WHITE;
	if (!ft_strncmp(mat_name, "#", 1))
		mat_name += 1;
	else
		mat_name += 2;
	col.hex = strtol(mat_name, NULL, 16);
	res.color = (cl_float4){(float)col.rgb.r / 255.0,
		(float)col.rgb.g / 255.0,
		(float)col.rgb.b / 255.0,
		1.0};
	return (res);
}

t_material	decide_material(char *mat_name)
{
	if (!ft_strncmp(mat_name, "0x", 2) || !ft_strncmp(mat_name, "#", 1))
		return (decide_color(mat_name));
	else if (ft_strequ(mat_name, "light"))
		return (MATERIAL_LIGHT);
	else if (ft_strequ(mat_name, "red"))
		return (MATERIAL_RED);
	else if (ft_strequ(mat_name, "green"))
		return (MATERIAL_GREEN);
	else if (ft_strequ(mat_name, "light basic"))
		return (MATERIAL_LIGHT_BASIC);
	else if (ft_strequ(mat_name, "light ambient"))
		return (MATERIAL_LIGHT_AMBIENT);
	else if (ft_strequ(mat_name, "mirror"))
		return (MATERIAL_MIRROR);
	else if (ft_strequ(mat_name, "glass"))
		return (MATERIAL_GLASS);
	else
		return (MATERIAL_WHITE);
}

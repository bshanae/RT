/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_translate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:55:09 by ashari            #+#    #+#             */
/*   Updated: 2019/10/01 18:09:14 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object_definition.h"

static const char	*object_translate_rm_objects(t_object_type type)
{
	if (type == object_type_limited)
		return ("Limited");
	else if (type == object_type_torus)
		return ("Torus");
	else if (type == object_type_mandelbulb)
		return ("Mandelbulb");
	else if (type == object_type_julia)
		return ("Julia");
	else if (type == object_type_perforated_cube)
		return ("Perforated cube");
	else if (type == object_type_explosion)
		return ("Explosion");
	else if (type == object_type_csg)
		return ("CSG");
	return ("Unknown");
}

const char			*object_translate(t_object_type type)
{
	if (type == object_type_light_ambient)
		return ("Ambient light");
	else if (type == object_type_light_point)
		return ("Point light");
	else if (type == object_type_light_direct)
		return ("Direct light");
	else if (type == object_type_sphere)
		return ("Sphere");
	else if (type == object_type_plane)
		return ("Plane");
	else if (type == object_type_cone)
		return ("Cone");
	else if (type == object_type_cylinder)
		return ("Cylinder");
	else if (type == object_type_box)
		return ("Box");
	else if (type == object_type_paraboloid)
		return ("Paraboloid");
	else if (type == object_type_moebius)
		return ("Moebius strip");
	else
		return (object_translate_rm_objects(type));
}
